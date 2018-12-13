#include <bits/stdc++.h>

using namespace std;

int in[17886], n, sum;

void go(int &idx) {
	int nChild=in[idx], nMeta=in[idx+1];
	idx+=2;
	for(int i=0; i<nChild; ++i) {
		go(idx);
	}
	for(int j=0; j<nMeta; ++j) {
		sum+=in[idx++];
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	while(cin>>in[n++]) {}

	int start=0;
	go(start);

	cout<<sum<<'\n';
	cerr<<(long double)clock()/CLOCKS_PER_SEC<<'\n';
    return 0;
}