#include <iostream>
#include <vector>

using namespace std;

const int GEN1=20;
const long long GEN2=50000000000LL;

string s;
int n;

struct Pattern {
	string pat;
	bool put;
	Pattern(string _pat, bool _put) {
		pat=_pat;
		put=_put;
	}
}; vector<Pattern> v;

void input() {
	freopen("i.txt", "r", stdin);
	string line;
	getline(cin, line);
	s="";
	for(int i=0; i<10000; ++i) s+='.';
	for(int i=15; i<(int)line.size(); ++i) s+=line[i]; 
	for(int i=0; i<10000; ++i) s+='.'; 
	n=(int)s.size();

	getline(cin, line);

	while(getline(cin, line)) {
		v.push_back(Pattern(line.substr(0, 5), line[9]=='.'?0:1));
	}
}

void part1() {
	string cpat;
	bool toPut, saveState[300000];
	for(int cgen=1; cgen<=GEN1; ++cgen) {
		for(int i=0; i<n; ++i) saveState[i]=0;
		for(int i=2; i<n-2; ++i) {
			cpat="";
			for(int j=i-2; j<=i+2; ++j) cpat+=s[j];
			toPut=0;
			for(Pattern curr:v) {
				if(curr.pat==cpat) {
					toPut=curr.put;
					break;
				}
			}
			saveState[i]=toPut;
		}
		for(int i=2; i<n-2; ++i) {
			if(saveState[i]) s[i]='#';
			else s[i]='.';
		}
	}

	int ans=0, numb=-30;
	for(char i:s) {
		if(i=='#') ans+=numb;
		numb++;
	}

	cout<<ans<<'\n';
}

void part2() {
	string cpat;
	bool toPut, saveState[30000];
	int maxans=INT_MIN, ans, numb, lastdiff=0;
	for(long long cgen=1; cgen<=GEN2; ++cgen) {
		for(int i=0; i<n; ++i) saveState[i]=0;
		for(int i=2; i<n-2; ++i) {
			cpat="";
			for(int j=i-2; j<=i+2; ++j) cpat+=s[j];
			toPut=0;
			for(Pattern curr:v) {
				if(curr.pat==cpat) {
					toPut=curr.put;
					break;
				}
			}
			saveState[i]=toPut;
		}
		for(int i=2; i<n-2; ++i) {
			if(saveState[i]) s[i]='#';
			else s[i]='.';
		}
		ans=0;	
		numb=-10000;
		for(char i:s) {
			if(i=='#') ans+=numb;
			numb++;
		}
		if(ans>maxans) {
			if(lastdiff==ans-maxans) {
				cout<<(GEN2-cgen*1LL)*lastdiff+ans<<'\n';
				break;
			} else lastdiff=ans-maxans;
			maxans=ans;
		} 
	}
}

int main() {
	input();
	//part1();
	part2();
	return 0;
}