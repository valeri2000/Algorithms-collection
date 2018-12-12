#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <ctime>

using namespace std;

priority_queue< pair<int, int> > q;
bool used[20001];
vector< pair<int, int> > v[20001];
int n, m, k, a, b, p, t, currdist, currv;
int x, w;
int dist[20001];

int main ()
{
	clock_t tStart = clock();
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
    	cin>>a>>b>>p;
        v[a].push_back(make_pair(b, p));
        v[b].push_back(make_pair(a, p));
    }
    for(int i=2;i<=n;++i)
    {
    	dist[i]=INT_MAX;
	}
	dist[1]=0;
	q.push(make_pair(0, 1));
	while(!q.empty())
	{
		currv=q.top().second;
		currdist=-q.top().first;
		q.pop();
		used[currv]=1;
		if(currdist>dist[currv])
		{
			continue;
		}
		for(int i=0;i<v[currv].size();++i)
		{
			x=v[currv][i].first;
			w=v[currv][i].second;
			if(!used[x] && dist[x]>dist[currv]+w)
			{
				dist[x]=dist[currv]+w;
				q.push(make_pair(-dist[x], x));
			}
		}
	}
	for(int i=2; i<=n; ++i)
    {
        cout<<"Dist from "<<i<<" is "<<dist[i]<<"\n";
    }
    return 0;
}
/*
8 11
1 2 10
1 4 8
1 3 20
3 4 3
2 6 10
3 5 7
4 5 5
5 6 8
5 7 1
6 7 5
6 8 8
*/
