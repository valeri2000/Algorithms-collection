#include <bits/stdc++.h>

#define time abac

using namespace std;

int n, m, a, b, ans, depth;

vector<int> v[10002];
bool used[10002], FOUND[10002];
int low[10002], time[10002], parent[10002];

void init()
{
    for(int i=1; i<=n; ++i)
    {
        v[i].clear();
        used[i]=FOUND[i]=0;
        low[i]=time[i]=0;
        parent[i]=-1;
    }
    ans=depth=0;
}

void art_points(int curr)
{
    int child=0;
    low[curr]=time[curr]=depth++;
    used[curr]=1;
    for(int i:v[curr])
    {
        if(!used[i])
        {
            child++;
            parent[i]=curr;
            art_points(i);
            low[curr]=min(low[curr], low[i]);
            if(parent[curr]==-1 && child>1) FOUND[curr]=1;
            else if(parent[curr]!=-1 && low[i]>=time[curr]) FOUND[curr]=1;
        }
        else if(parent[curr]!=i) low[curr]=min(low[curr], time[i]);
    }
}

int main ()
{
    //freopen("i.txt", "r", stdin);
    while(1)
    {
        scanf("%d %d", &n, &m);
        if(n==0 && m==0) break;
        init();
        for(int i=0; i<m; ++i)
        {
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        art_points(1);
        for(int i=1; i<=n; ++i) if(FOUND[i]) ans++;
        printf("%d\n", ans);
    }
    return 0;
}