#include <bits/stdc++.h>

using namespace std;

const int M1=10001;
const int M2=19684;

char input[M1];
set <string> s;
bool used[M1][M2];

void solve(int pos, int prev)
{
    if(used[pos][prev])
    {
        return;
    }
    used[pos][prev]=true;
    if(pos>=6)
    {
        string curr;
        curr.push_back(input[pos-1]);
        curr.push_back(input[pos]);
        s.insert(curr);
        int key=(input[pos-1]-'a'+1)*27+(input[pos]-'a'+1);
        if(prev!=key)
        {
            solve(pos-2, key);
        }
    }
    if(pos>=7)
    {
        string curr;
        curr.push_back(input[pos-2]);
        curr.push_back(input[pos-1]);
        curr.push_back(input[pos]);
        s.insert(curr);
        int key=(input[pos-2]-'a'+1)*729+(input[pos-1]-'a'+1)*27+(input[pos]-'a'+1);
        if(prev!=key)
        {
            solve(pos-3, key);
        }
    }
}

int main ()
{
    scanf("%s", &input);
    solve(strlen(input)-1, 0);
    printf("%d\n", s.size());
    for(set <string>::iterator it=s.begin();it!=s.end();++it)
    {
        string curr=*it;
        printf("%c%c", curr[0], curr[1]);
        if(curr.size()==3)
        {
            printf("%c", curr[2]);
        }
        printf("\n");
    }
    return 0;
}