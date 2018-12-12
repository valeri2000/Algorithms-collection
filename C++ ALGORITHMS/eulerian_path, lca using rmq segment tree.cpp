#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <ctime>
#include <climits>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <utility>

#define endl '\n'
#define _ ios::sync_with_stdio(false), cin.tie(NULL)
#define iread(sss) freopen((sss), "r", stdin)
#define ff first
#define ss second
#define all(abcc) (abcc).begin(), (abcc).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// clock_t tstart;void sc(){tstart=clock();} void pc(){printf("time=%.3f\n", (clock()-tstart)/(CLOCKS_PER_SEC*1.0));}
const int N=(int)1e5+3;

int n, m, a, b;

vector<int> neigh[N], path;
int level[N], foccur[N];
bool used[N];

void eul(int curr, int prev, int lvl) {
	used[curr]=1;
	level[curr]=lvl;
	path.push_back(curr);
	foccur[curr]=(int)path.size()-1;
	for(int i:neigh[curr]) {
		if(!used[i]) {
			eul(i, curr, lvl+1);
		}
	}
	if(prev!=-1) path.push_back(prev);
}

pii tree[4*N];

void buildTree(int node, int l, int r) {
	if(l>=r) return;
	if(l+1==r) {
		tree[node]={level[path[l]], path[l]};
		return;
	}
	buildTree(node+node, l, (l+r)>>1);
	buildTree(node+node+1, (l+r)>>1, r);
	if(tree[node+node].ff<tree[node+node+1].ff) tree[node]=tree[node+node];
	else tree[node]=tree[node+node+1];
}

pii query(int node, int ql, int qr, int l, int r) {
	if(ql>=r || qr<=l) return {INT_MAX, 0};
	if(ql<=l && r<=qr) return tree[node];
	pii aa=query(node+node, ql, qr, l, (l+r)>>1);
	pii bb=query(node+node+1, ql, qr, (l+r)>>1, r);
	if(aa.ff<bb.ff) return aa;
	return bb;
}

int main() {
    //iread("i1.txt");
    _;
    cin>>n>>m;
    for(int i=0; i<m; ++i) {
    	cin>>a>>b;
    	neigh[a].push_back(b);
    	neigh[b].push_back(a);
    }
    eul(1, -1, 0);
    for(auto i:path) cout<<i<<" "; 
    cout<<endl;
	buildTree(1, 0, (int)path.size());
	while(cin>>a>>b) {
		if(foccur[a]>foccur[b]) swap(a, b);
		cout<<query(1, foccur[a], foccur[b]+1, 0, (int)path.size()).ss<<endl;
	}
    return 0;
}