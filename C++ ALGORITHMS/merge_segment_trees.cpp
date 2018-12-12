/*
    SPOJ - KQUERYO
*/
#include <bits/stdc++.h>

using namespace std;

int n, t, p, q, k, lastans=0;

int in[30001];
vector<int> tree[4*30001];

void build(int node=1, int l=0, int r=n)
{
    if(l+1==r)
    {
        tree[node].push_back(in[l]);
        return;
    }
    int mid=(l+r)>>1;
    build(node<<1, l, mid);
    build((node<<1)+1, mid, r);
    tree[node].resize((int)tree[node<<1].size()+(int)tree[(node<<1)+1].size());
    merge(tree[node<<1].begin(), tree[node<<1].end(), tree[(node<<1)+1].begin(), tree[(node<<1)+1].end(),tree[node].begin());
}

int query(int node=1, int l=0, int r=n)
{
    if(p>=r || q<=l) return 0;
    if(p<=l && r<=q) return  tree[node].end()-upper_bound(tree[node].begin(), tree[node].end(), k);
    int mid=(l+r)>>1;
    return query(node<<1, l, mid)+query((node<<1)+1, mid, r);
}

int main()
{
    freopen("i.txt","r",stdin);
    scanf("%d", &n);
    for(int i=0; i<n; ++i) scanf("%d", &in[i]);
    build();
    //for(int i:tree[1]) printf("%d ", i);
    printf("\n");
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &p, &q, &k);
        p=p^lastans;
        if(p<1) p=1;
        q=q^lastans;
        if(q>n) q=n;
        if(p>q)
        {
            lastans=0;
            printf("0\n");
            continue;
        }
        k=k^lastans;
        --p;
        lastans=query();
        printf("%d\n", lastans);
    }
    return 0;
}
