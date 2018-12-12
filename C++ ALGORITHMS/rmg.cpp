#include <cstdio>
#include <cmath>

using namespace std;

const int nMax=1<<20, logMax=20;

int n, m, input[nMax], rmg[nMax][logMax+1], q1, q2, q3;

inline int min(int ff, int ss)
{
    if(ff>ss)
    {
        return ss;
    }
    return ff;
}

void preprocess()
{
    for(int i=0; i<n; ++i)
    {
        rmg[i][0]=i;
    }
    int myLog=log2(n);
    for(int j=1; j<=myLog; ++j)
    {
        for(int i=0; i+(1<<j)-1<n; ++i)
        {
            if(input[rmg[i][j-1]]<input[rmg[i+(1<<(j-1))][j-1]])
            {
                rmg[i][j]=rmg[i][j-1];
            }
            else
            {
                rmg[i][j]=rmg[i+(1<<(j-1))][j-1];
            }
        }
    }
}

void query(int &ans, int l, int r)
{
    int m=r-l+1, k=log2(m);
    ans=min(input[rmg[l][k]], input[rmg[l+m-(1<<k)][k]]);
}

int main ()
{
    freopen("input.txt", "r", stdin);
    int cntTests;
    scanf("%d", &cntTests);
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &input[i]);
    }
    preprocess();
    for(int i=0; i<m; ++i)
    {
        scanf("%d %d", &q1, &q2);
        query(q3, q1, q2);
        printf("%d\n", q3);
    }
    return 0;
}
