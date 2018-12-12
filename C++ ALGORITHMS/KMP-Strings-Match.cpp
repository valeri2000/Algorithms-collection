#include <iostream>
using namespace std;

int br=0;
int lps[16];

void computeLPS(string pat, int spat, int lps[]);
void KMP(string pat, string txt)
{
    int spat=pat.size(), N=txt.size(), i=0, j=0;
    computeLPS(pat, spat, lps);
    br=0;
    while(i<N)
    {
        if(pat[j]==txt[i])
        {
            i++;
            j++;
        }
        if(j==spat)
        {
            br++;
            cout<<"Found match at index "<<i-j<<endl;
            j=lps[j-1];
        }
        else
        if(i<N && pat[j]!=txt[i])
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                i++;
            }
        }
    }
}

void computeLPS(string pat, int spat, int lps[])
{
    int len=0, i=1;
    lps[0]=0;
    while(i<spat)
    {
        if(pat[i]==pat[len])
        {
            lps[i++]=++len;
        }
        else
        {
            if(len!=0)
            {
                len=lps[len-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}

int main()
{
    string a, b;
    cin>>a>>b;
    KMP(b, a);
    cout<<br<<"\n";
    return 0;
}
