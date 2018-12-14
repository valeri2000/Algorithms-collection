#include <iostream>
#include <vector>

using namespace std;

const string RECIPIES="170641";
const int DIGITS=(int)RECIPIES.size();

vector<int> v, comp;

bool pb(int numb) {
	v.push_back(numb);
	if((int)v.size()>=DIGITS) {
		string curr="";
		for(int i=(int)v.size()-DIGITS; i<(int)v.size(); ++i) curr+=(v[i]+'0');
		if(curr==RECIPIES) return true;
	}
	return false;
}

int main() {
	v.push_back(3), v.push_back(7);

	int elf1=0, elf2=1, cnt;

	for(cnt=1; ; ++cnt) {
		int csum=v[elf1]+v[elf2];
		if(csum<10) {
			if(pb(csum)) break;
		}
		else {
			if(pb(csum/10)) break;
			if(pb(csum%10)) break;
		}

		elf1+=(v[elf1]+1);
		elf1%=(int)v.size();
		elf2+=(v[elf2]+1);
		elf2%=(int)v.size();

		//for(auto i:v) cout<<i<<" ";
		//cout<<"| elf1="<<elf1<<", elf2="<<elf2<<'\n';
	}

	cout<<(int)v.size()-DIGITS<<'\n';
	return 0;
}