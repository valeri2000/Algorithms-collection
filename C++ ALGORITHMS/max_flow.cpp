#include <cstdio>
#include <cstring>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

const int sizeG=1024;
int n, m, Graph[sizeG][sizeG], parent[sizeG], a, b, c, curr, max_flow, curr_flow, i1;
bool used[sizeG];
queue <int> q;

bool bfs(int src, int tg)
{
    memset(used, 0, n);
    q.push(src);
    parent[src]=-1;
    used[src]=1;
    while(!q.empty())
    {
        curr=q.front();
        q.pop();
        for(int i=0;i<n;++i)
        {
            if(!used[i] && Graph[curr][i])
            {
                q.push(i);
                parent[i]=curr;
                used[i]=1;
            }
        }
    }
    if(used[tg])
    {
        return 1;
    }
    return 0;
}

int MaxFlow(int s, int t)
{
    max_flow=0;
    while(bfs(s, t))
    {
        curr_flow=INT_MAX;
        for(int i=t;i!=s;i=parent[i])
        {
            i1=parent[i];
            curr_flow=min(curr_flow, Graph[i1][i]);
        }
        for(int i=t;i!=s;i=parent[i])
        {
            i1=parent[i];
            Graph[i1][i]-=curr_flow;
            Graph[i][i1]+=curr_flow;
        }
        max_flow+=curr_flow;
    }
    return max_flow;
}

int main ()
{
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;++i)
    {
        scanf("%d %d %d", &a, &b, &c);
        Graph[a][b]=c;
    }
    printf("%d\n", MaxFlow(0, 7));
    return 0;
}
/*
6 10
0 1 16
0 2 13
1 2 10
2 1 4
1 3 12
3 2 9
2 4 14
4 5 4
3 5 20
4 3 7
------
23

8 15
0 1 10
0 2 5
0 3 15
1 2 4
2 3 4
1 4 9
1 5 15
2 5 8
6 2 6
3 6 16
4 5 15
5 6 15
6 7 10
5 7 10
4 7 10
*/
