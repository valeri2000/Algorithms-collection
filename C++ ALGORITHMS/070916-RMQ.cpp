#include <cstdio>
#include <algorithm>

using namespace std;

const int nMax=1<<17;

int n, x, q, a, b, tree[nMax];

void updateTree(int l, int r, int currl, int currr, int node, int vl)
{
    if(r<currl || l>currr)
    {
        return;
    }
    if(currl==currr)
    {
        tree[node]=vl;
        return;
    }
    updateTree(l, r, currl, (currl+currr)/2, node*2, vl);
    updateTree(l, r, (currl+currr)/2+1, currr, node*2+1, vl);
    tree[node]=min(tree[node*2], tree[node*2+1]);
    return;
}

int printTree(int l, int r, int currl, int currr, int node)
{
    if(r<currl || l>currr)
    {
        return nMax;
    }
    if(l<=currl && currr<=r)
    {
        return tree[node];
    }
    return min(printTree(l, r, (currl+currr)/2+1, currr, node*2+1),
               printTree(l, r, currl, (currl+currr)/2, node*2));

}

int main ()
{
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &x);
        updateTree(i+1, i+1, 1, n, 1, x);
    }
    scanf("%d", &q);
    for(int k=0; k<q; ++k)
    {
        scanf("%d %d %d", &x, &a, &b);
        if(x==1)
        {
            updateTree(a, a, 1, n, 1, b);
        }
        else
        {
            printf("%d\n", printTree(a, b, 1, n, 1));
        }
    }
    return 0;
}
