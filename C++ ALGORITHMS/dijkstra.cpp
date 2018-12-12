#include <cstdio>
#include <limits.h>
using namespace std;

int n, m, a, b, c, src, posit;
int Graph[1024][1024], dist[1024];
bool used[1024];

void fill()
{
    for(int i=1;i<=n;++i)
    {
        dist[i]=INT_MAX;
    }
}

int minpos()
{
    int xmin=INT_MAX, pos;
    for(int i=1;i<=n;++i)
    {
        if(xmin>dist[i]&&used[i]==0)
        {
            xmin=dist[i];
            pos=i;
        }
    }
    return pos;
}
int main ()
{
    scanf("%d%d", &n, &m);
    for(int i=0;i<m;++i)
    {
        scanf("%d%d%d", &a, &b, &c);
        Graph[a][b]=c;

    }
    printf("Source=");
    scanf("%d", &src);
    fill();
    dist[src]=0;
    for(int xcount=1;xcount<=n;++xcount)
    {
        posit=minpos();
        used[posit]=1;
        for(int i=1;i<=n;++i)
        {
            if(used[i]==0&&Graph[posit][i]&&dist[posit]!=INT_MAX&&dist[posit]+Graph[posit][i]<dist[i])
            {
                dist[i]=dist[posit]+Graph[posit][i];
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        printf("Min Way from %d to %d is %d\n", src, i, dist[i]);
    }
    return 0;
}
/*
9 14
1 2 4
1 8 8
2 8 11
2 3 8
8 7 1
8 9 7
3 9 2
7 9 6
7 6 2
3 6 4
3 4 7
4 5 9
4 6 14
6 5 10
*/
