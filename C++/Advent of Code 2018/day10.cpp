#include <iostream>
#include <vector>
#include <unordered_set>
#include <ctime>

using namespace std;

struct Point {
	int x, y, vx, vy;
	Point(int _x, int _y, int _vx, int _vy) {
		x=_vx, y=_vy, vx=_x, vy=_y;
	}
}; vector<Point> v;

string line;
int idx;
unordered_multiset<int> s;

int parseNext(int &idx) {
	for(; line[idx]<'0' || line[idx]>'9'; ++idx) {}
	int ret=0, minus;
	if(line[idx-1]=='-') minus=-1;
	else minus=1;
	for(; line[idx]>='0' && line[idx]<='9'; ++idx) ret=ret*10+line[idx]-'0';
	return ret*minus;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while(getline(cin, line)) {
		idx=0;
		v.push_back(Point(parseNext(idx), parseNext(idx), parseNext(idx), parseNext(idx)));
	}
	int cnt=0;
	for(int time=1500; time<=20000; ++time) {
		int xmin=INT_MAX, xmax=INT_MIN, ymin=INT_MAX, ymax=INT_MIN;
		for(int i=0; i<(int)v.size(); ++i) {
			auto it=s.find(v[i].x*31*31+v[i].y);
			if(it!=s.end()) s.erase(it);
			v[i].x+=v[i].vx;
			v[i].y+=v[i].vy;
			xmin=min(xmin, v[i].x);
			xmax=max(xmax, v[i].x);
			ymin=min(ymin, v[i].y);
			ymax=max(ymax, v[i].y);
			s.insert(v[i].x*31*31+v[i].y);
		}
		cout<<xmax-xmin<<endl;
		cnt++;
		if(cnt>10) break;
		if(xmax-xmin<11) {
			cout<<time<<'\n';
			for(int i=xmin-1; i<=xmax+1; ++i) {
				for(int j=ymin-1; j<=ymax+1; ++j) {
					if(s.find(i*31*31+j)!=s.end()) cout<<'*';
					else cout<<'.';
				}
				cout<<'\n';
			}
			break;
		}
	}
    return 0;
}