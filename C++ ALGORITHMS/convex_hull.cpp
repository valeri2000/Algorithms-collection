#include <cstdio>
#include <utility>
#include <algorithm>
#include <stack>

using namespace std;

int n, miny=1e6+1, minyIdx;
pair<int, int> p0, top;


pair<int, int> points[1024];
stack<pair<int, int> > st;

int distBetween(pair<int, int> ff, pair<int, int> ss)
{
    return (ff.first-ss.first)*(ff.first-ss.first)+(ff.second-ss.second)*(ff.second-ss.second);
}

short orientation(pair<int, int> a0, pair<int, int> ff, pair<int, int> ss)
{
    int oArea=(a0.first-ff.first)*(a0.second+ff.second)+(ff.first-ss.first)*(ff.second+ss.second)+(ss.first-a0.first)*(ss.second+a0.second);
    if(oArea>0)
    {
        return -1;
    }
    if(oArea<0)
    {
        return 1;
    }
    return 0;
}

bool cmp(pair<int, int> ff, pair<int, int> ss)
{
    short ans=orientation(p0, ff, ss);
    if(ans==0)
    {
        return distBetween(p0, ff)<distBetween(p0, ss);
    }
    return ans==-1;
}

int main ()
{
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d %d", &points[i].first, &points[i].second);
    }
    // 1. Find the bottom most point
    for(int i=0; i<n; ++i)
    {
        if(miny>points[i].second)
        {
            miny=points[i].second;
            minyIdx=i;
        }
    }
    p0=points[minyIdx];
    swap(points[0], points[minyIdx]);
    //sort by polar angle counter clockwise
    sort(points+1, points+n, cmp);
    int m=1; // Initialize size of modified array
    for(int i=1; i<n; ++i)
    {
        while(i<n-1 && orientation(p0, points[i], points[i+1])==0)
        {
            i++;
        }
        points[m++]=points[i];
    }
    for(int i=0; i<3; ++i)
    {
        st.push(points[i]);
    }
    for(int i=3; i<m; ++i)
    {
        top=st.top();
        st.pop();
        while(orientation(st.top(), top, points[i])!=-1)
        {
            top=st.top();
            st.pop();
        }
        st.push(top);
        st.push(points[i]);
    }
    while(!st.empty())
    {
        printf("%d %d\n", st.top().first, st.top().second);
        st.pop();
    }
    return 0;
}
