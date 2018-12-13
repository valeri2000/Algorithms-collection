#include <iostream>

using namespace std;

const int n=435, m=71184;

long long arr[10000000], sarr=10, points[n+1];

int main() {
	//ios::sync_with_stdio(false); cin.tie(NULL);
	long long currm=9, posCurr=3, currplayer=9;
	arr[0]=0, arr[1]=8, arr[2]=4, arr[3]=9, arr[4]=2, 
	arr[5]=5, arr[6]=1, arr[7]=6, arr[8]=3, arr[9]=7;
	currm++;
	currplayer++;
	while(currm<=m) {
		if(currplayer>n) currplayer=1;
		if(currm%23) {
			int x=(posCurr+1)%sarr;
			int y=(x+1)%sarr;
			long long help=currm;
			if(y==0) {
				posCurr=sarr;
				arr[sarr++]=help;
			} else {
				sarr++;
				posCurr=y;
				for(int i=y; i<sarr; ++i) {
					swap(arr[i], help);
				}
			}
		} else {
			points[currplayer]+=currm;
			int steps=6, j;
			for(j=posCurr-1; steps>0 && j>=0; --j) {
				steps--;
			}
			if(steps==0) {
				posCurr=j;
				sarr--;
				points[currplayer]+=arr[j];
				for(int i=j; i<sarr; ++i) arr[i]=arr[i+1];
			} else {
				for(j=sarr-1; steps>0 && j>=0; --j) steps--;
				points[currplayer]+=arr[j];
				sarr--;
				posCurr=j;
				for(int i=j; i<sarr; ++i) arr[i]=arr[i+1];
			}
		}
		currm++;
		currplayer++;
	}
	long long xmax=0;
	for(int i=1; i<=n; ++i) xmax=max(xmax, points[i]);
	cout<<xmax<<'\n';
	return 0;
}