#include <iostream>

using namespace std;

string s[101];
int n, m;

short dirPlus[3]={2, -1, 3};

struct Cart {
	short dir; //0 - up; 1 - down; 2 - left; 3 - right
	int x, y, cntPlus;

	Cart(int _x, int _y, short _posx, short _posy) {
		x=_x;
		y=_y;
		posx=_posx;
		posy=_posy;
		cntPlus=-1;
	}
	
	void move() {
		if(dir==0) y--;
		else if(dir==1) y++;
		else if(dir==2) x--;
		else x++;

		if(s[x][y]=='+') {
			int sdir=dirPlus[(++cntPlus)%3];
			if(sdir!=-1) dir=sdir;
		} else if(s[x][y]=='/') {

		}
	}
};

int main() {
	string line;
	while(getline(cin, line)) {
		s[n++]=line;
		m=max(m, (int)line.size());
	}
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			if(s[i][j]=='^') {

			}
		}
	}
	return 0;
}
