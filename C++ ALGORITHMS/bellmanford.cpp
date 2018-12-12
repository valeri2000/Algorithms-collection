#include <cstdio>
#include <climits>
using namespace std;

struct MyStruct
{
    int from;
    int to;
    int v;
};

int n, m, dist[512];
MyStruct A[256];
bool Better;

int main ()
{
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;++i)
    {
        scanf("%d %d %d", &A[i].from, &A[i].to, &A[i].v);
    }
    for(int i=1;i<n;++i)
    {
        dist[i]=INT_MAX;
    }
    dist[0]=0;
    for(int i=1;i<=n-1;++i)
    {
        Better=0;
        for(int j=0;j<m;++j)
        {
            if(dist[A[j].from]!=INT_MAX && dist[A[j].to]>dist[A[j].from]+A[j].v)
            {
                dist[A[j].to]=dist[A[j].from]+A[j].v;
                Better=1;
            }
        }
        if(!Better)
        {
            break;
        }
    }
    for(int i=1;i<n;++i)
    {
        printf("Distance from 0 to %d is %d\n", i, dist[i]);
    }
    return 0;
}
/*
7 12
0 1 1
0 3 7
0 5 5
1 2 -2
1 3 5
2 4 -1
2 3 6
3 4 -1
3 6 2
3 5 -3
4 6 3
5 6 2
*/
