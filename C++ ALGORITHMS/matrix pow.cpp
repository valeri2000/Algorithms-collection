#include <cstdio>

using namespace std;

const int mod=1000000007;

struct MyStruct
{
    int arr[2][2];
};

long long n;
MyStruct a, c, ba, x;

void solve2()
{
    printf("%d\n", (int)((6*x.arr[0][0]+2*x.arr[0][1])%mod));
    return;
}

MyStruct solve(long long want)
{
    if(want==1)
    {
        return a;
    }
    else
    if(want%2==0)
    {
        MyStruct curr=solve(want/2);
        for(int i=0; i<2; ++i)
        {
            for(int j=0; j<2; ++j)
            {
                c.arr[i][j]=0;
            }
        }
        for(int i=0; i<2; ++i)
        {
            for(int j=0; j<2; ++j)
            {
                for(int l=0; l<2; ++l)
                {
                    c.arr[i][j]=(c.arr[i][j]+curr.arr[i][l]*curr.arr[l][j])%mod;
                }
            }
        }
        return c;
    }
    else
    {
        MyStruct curr=solve(want/2);
        for(int i=0; i<2; ++i)
        {
            for(int j=0; j<2; ++j)
            {
                c.arr[i][j]=0;
                ba.arr[i][j]=0;
            }
        }
        for(int i=0; i<2; ++i)
        {
            for(int j=0; j<2; ++j)
            {
                for(int l=0; l<2; ++l)
                {
                    c.arr[i][j]=(c.arr[i][j]+curr.arr[i][l]*curr.arr[l][j])%mod;
                }
            }
        }
        for(int i=0; i<2; ++i)
        {
            for(int j=0; j<2; ++j)
            {
                for(int l=0; l<2; ++l)
                {
                    ba.arr[i][j]=(ba.arr[i][j]+c.arr[i][l]*a.arr[l][j])%mod;
                }
            }
        }
        return ba;
    }
}

int main ()
{
    scanf("%lld", &n);
    if(n==1)
    {
        printf("0\n");
        return 0;
    }
    if(n==2)
    {
        printf("2\n");
        return 0;
    }
    if(n==3)
    {
        printf("3\n");
        return 0;
    }
    a.arr[0][0]=4, a.arr[0][1]=-2, a.arr[1][0]=1, a.arr[1][1]=0;
    x=solve(n-3);
    solve2();
    return 0;
}
