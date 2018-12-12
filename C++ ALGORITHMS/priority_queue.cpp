#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

struct Person
{
    int numb;
    string name;
};

struct compare
{
    bool operator()(const Person& a, const Person& b)
    {
        if(a.numb<b.numb)
            return 1;
        if(a.numb==b.numb)
        {
            return a.numb<b.numb;
        }
        return 0;
    }
};
int main()
{
    int n;
    Person a[1024], curr;
    priority_queue<Person, vector<Person>, compare> q;
    scanf("%d", &n);
    for(int i=0;i<n;++i)
    {
        scanf("%d", &a[i].numb);
        cin>>a[i].name;
        q.push(a[i]);
    }
    while(!q.empty())
    {
        curr=q.top();
        q.pop();
        cout<<"Number "<<curr.numb<<" - Name:"<<curr.name<<endl;
    }
    return 0;
}
