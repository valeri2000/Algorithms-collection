#include <cstdio>
#include <queue>
using namespace std;
int n, m, a, b, start, finish, curr, A[1024][1024], BestWay[1024];
bool used[1024];
queue<int> q;
int main ()
{
    scanf("%d%d", &n, &m);
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d", &a, &b);
        A[a][b]=1;
        A[b][a]=1;
    }
    start=1;
    q.push(start);
    used[start]=1;
    while(!q.empty())
    {
        curr=q.front();
        q.pop();
        for(int i=1;i<=n;++i)
        {
            if(!used[i]&&A[i][curr])
            {
                q.push(i);
                used[i]=1;
                BestWay[i]=curr;
            }
        }
    }
    finish=5;
    printf("%d", finish);
    int x=BestWay[finish];
    while(x!=0)
    {
        printf(" %d", x);
        x=BestWay[x];
    }
    printf("\n");
    return 0;
}
/*
5 8
1 3
1 4
3 5
4 5
1 2
2 3
2 4
2 5
*/
