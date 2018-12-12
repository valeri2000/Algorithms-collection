#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int o, ans, cnt=1;
string s;

int main ()
{
    //freopen("i.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(1)
    {
        cin>>s;
        o=ans=0;
        bool fl=false;
        for(int i=0; i<(int)s.size(); ++i)
        {
            if(s[i]=='-')
            {
                fl=true;
                break;
            }
        }
        if(fl) break;
        for(int i=0; i<(int)s.size(); ++i)
        {
            if(s[i]==' ') continue;
            if(s[i]=='{') o++;
            else o--;
            if(o<0) {ans++; o=1;}
            if(o>=(int)s.size()-i) {ans++; o-=2;}
        }
        cout<<cnt++<<". "<<ans<<endl;
    }
    return 0;
}
