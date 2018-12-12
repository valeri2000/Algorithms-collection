#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int n;

long long dp[1<<21];
bool okey[1<<5][1<<5];

long long solve(int mask)
{
    int idx=__builtin_popcount(mask); //count how many bits are ready(1)
    if(idx==n) return 1; //if they are all, we have found a valid solution
    if(dp[mask]!=-1) return dp[mask]; //we have already calculated this
    long long ans=0;
    for(int i=0; i<n; ++i)
        if(((mask>>i)&1)==0 && okey[idx][i]) ans+=solve(mask|(1<<i)); 
        //if ith bit is not ready and it is compatible
    return dp[mask]=ans;
}

int main ()
{
    //freopen("i.txt", "r", stdin);
    ios::sync_with_stdio(false); cin.tie(NULL);
    int tests;
    cin>>tests;
    for(; tests--; )
    {
        cin>>n;
        for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) cin>>okey[i][j];
        memset(dp, (-1), sizeof dp);
        cout<<solve(0)<<endl;
    }
    return 0;
}