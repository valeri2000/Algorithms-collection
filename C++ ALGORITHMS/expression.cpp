#include <bits/stdc++.h>

using namespace std;

string input;

int preority(char ch)
{
    if(ch=='+' || ch=='-')
    {
        return 1;
    }
    if(ch=='*' || ch=='/')
    {
        return 2;
    }
    if(ch=='^')
    {
        return 3;
    }
    return 0;
}

string Traslate(string input)
{
    stack<char> st;
    char currc, stop;
    int j;
    string ready="";
    st.push('(');
    for(int i=0; i<input.size(); ++i)
    {
        currc=input[i];
        if(currc>='0' && currc<='9')
        {
            ready+=currc;
            for(j=i+1; j<input.size() && (input[j]>='0' && input[j]<='9') || (input[j]=='.'); ++j)
            {
                ready+=input[j];
            }
            ready+='#';
            i=j-1;
        }
        else if(currc=='+' || currc=='-' || currc=='*' || currc=='/' || currc=='^')
        {
            stop=st.top();
            while(preority(stop)>=preority(currc))
            {
                st.pop();
                ready+=stop;
                stop=st.top();
            }
            st.push(currc);
        }
        else if(currc=='(')
        {
            st.push(currc);
        }
        else
        {
            stop=st.top();
            while(stop!='(')
            {
                st.pop();
                ready+=stop;
                stop=st.top();
            }
            st.pop();
        }
    }
    stop=st.top();
    while(stop!='(')
    {
        st.pop();
        ready+=stop;
        stop=st.top();
    }
    st.pop();
    while(!st.empty())
    {
        stop=st.top();
        st.pop();
        ready+=stop;
    }
    return ready;
}

double xpow(double aa, int bb)
{
    if(bb==1)
    {
        return aa;
    }
    double cc=xpow(aa, bb/2);
    if(bb%2==0)
    {
        return cc*cc;
    }
    else
    {
        return cc*cc*aa;
    }
}

double Calculate(string input)
{
    stack<double> x;
    char currc, curr[16];
    int j, idx;
    double first, second;
    for(int i=0; i<input.size(); ++i)
    {
        currc=input[i];
        if(currc>='0' && currc<='9')
        {
            idx=0;
            curr[idx++]=currc;
            for(j=i+1; j<input.size() && input[j]!='#'; ++j)
            {
                curr[idx++]=input[j];
            }
            curr[idx++]='\0';
            i=j;
            x.push(atof(curr));
        }
        else
        {
            second=x.top();
            x.pop();
            first=x.top();
            x.pop();
            if(currc=='+')
            {
                first=first+second;
            }
            else if(currc=='-')
            {
                first=first-second;
            }
            else if(currc=='*')
            {
                first=first*second;
            }
            else if(currc=='/')
            {
                first=first/second;
            }
            else
            {
                first=xpow(first, (int)second);
            }
            x.push(first);
        }
    }
    return x.top();
}

int main ()
{
    cin>>input;
    cout<<Calculate(Traslate(input))<<endl;
    return 0;
}
