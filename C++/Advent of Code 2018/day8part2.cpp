#include <bits/stdc++.h>

using namespace std;

int in[17886], n, nodeNumb;
vector<int> v[17886];

int go(int &idx) {
	nodeNumb++;
	int z=nodeNumb, nChild=in[idx], nMeta=in[idx+1];
	idx+=2;
	v[z].push_back(0);
	for(int i=0; i<nChild; ++i) {
		v[z].push_back(go(idx));
	}
	int metsum=0;
	if(nChild==0) {
		for(int j=0; j<nMeta; ++j) {
			metsum+=in[idx++];
		}
	} else {
		for(int j=0; j<nMeta; ++j) {
			if(in[idx]<(int)v[z].size())
				metsum+=v[z][in[idx]];
			idx++;
		}
	}
	return metsum;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	while(cin>>in[n++]) {}

	int start=0;
	cout<<go(start)<<'\n';
	cerr<<(double)clock()/CLOCKS_PER_SEC<<'\n';

    return 0;
}