#include <cstdio>
#include <cstring>

using namespace std;

const int SIZE=100002;

int t, n, c, type, p, q;
long long v;

long long lazy[4*SIZE], tree[4*SIZE];

void update(int node=1, int l=0, int r=n)
{
    if(lazy[node])
    {
        tree[node]+=(r-l)*lazy[node];
        if(l!=r-1)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(q<=l || r<=p) return;
    if(p<=l && r<=q)
    {
        tree[node]+=(r-l)*v;
        if(l!=r-1)
        {
            lazy[node*2]+=v;
            lazy[node*2+1]+=v;
        }
        return;
    }
    int mid=(l+r)/2;
    update(node*2, l, mid);
    update(node*2+1, mid, r);
    tree[node]=tree[node*2]+tree[node*2+1];
}

long long query(int node=1, int l=0, int r=n)
{
    if(lazy[node])
    {
        tree[node]+=(r-l)*lazy[node];
        if(l!=r-1)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(q<=l || r<=p) return 0; //qr<=l || r<=ql
    if(p<=l && r<=q) return tree[node];
    int mid=(l+r)/2;
    return query(node*2, l, mid)+query(node*2+1, mid, r);
}

int main ()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &c);
        memset(tree, 0, sizeof tree);
        memset(lazy, 0, sizeof lazy);
        while(c--)
        {
            scanf("%d %d %d", &type, &p, &q);
            --p;
            if(type) printf("%lld\n", query());
            else
            {
                scanf("%lld", &v);
                update();
            }
        }
    }
    return 0;
}
