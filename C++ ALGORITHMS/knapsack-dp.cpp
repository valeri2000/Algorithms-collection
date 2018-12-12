/*
----------------------------------------------------
http://www.math.bas.bg/infos/files/2013-04-01-B1.pdf
----------------------------------------------------
*/
#include <cstdio>
#include <algorithm>
using namespace std;

struct Novel
{
    int pg;
    double vl;
};
Novel A[1002];
int n, m;
double dp[1002][1002];

bool cmp(Novel first, Novel second)
{
    if(first.pg==second.pg)
    {
        return first.vl<second.vl;
    }
    return first.pg<second.pg;
}

int main ()
{
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;++i)
    {
        scanf("%d %lf", &A[i].pg, &A[i].vl);
    }
    sort(A, A+n, cmp);
    for(int i=n-1;i>=0;--i)
    {
        A[i+1]=A[i];
    }
    dp[0][0]=0;
    for(int i=1;i<1001;++i)
    {
        dp[0][i]=0;
        dp[i][0]=0;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(j==A[i].pg)
            {
                dp[i][j]=max(A[i].vl, dp[i-1][j]);
            }
            else
            if(j>A[i].pg)
            {
                dp[i][j]=max(dp[i-1][j], A[i].vl+dp[i-1][j-A[i].pg]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    printf("%.2f\n", dp[n][m]);
    return 0;
}

/*
5 8
2 10.20
3 13.42
1 15.12
4 21.23
2 9.45
*/
