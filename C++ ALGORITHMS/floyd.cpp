#include <cstdio>
#include <iostream>
#include <limits.h>
using namespace std;
int n, m, a, b, c;
int Graph[1024][1024];
int main ()
{
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(i==j)
            {
                Graph[i][j]=0;
            }
            else
            {
                Graph[i][j]=INT_MAX;
            }
        }
    }
    for(int i=0;i<m;++i)
    {
        scanf("%d%d%d", &a, &b, &c);
        Graph[a][b]=c;
        Graph[b][a]=c;
    }
    for(int k=1;k<=n;++k)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(Graph[i][k]<INT_MAX&&Graph[k][j]<INT_MAX)
                    Graph[i][j]=min(Graph[i][j], Graph[i][k]+Graph[k][j]);
            }
        }
    }
    for(int i=1;i<n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            printf("Min Way from %d to %d is %d\n", i, j, Graph[i][j]);
        }
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
