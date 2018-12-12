#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int pre[1024], low[1024], a, b;
int bridges=0;
int n, m;
int cnt=0;
vector<int> vec[1024];

void dfs(int u, int v)
{
    pre[v]=cnt++;
    low[v]=pre[v];
    //cout<<"Visiting "<<v<<" with parent "<<u<<" and setting pre["<<v<<"]="<<pre[v]<<" and low["<<v<<"]="<<low[v]<<endl;
    for(int kk=0; kk<(int)vec[v].size(); ++kk)
    {
        int w=vec[v][kk];
        if(pre[w]==-1)
        {
            //cout<<"Neighb of "<<v<<" ="<<w<<" is not visited before!\n";
            dfs(v, w);
            low[v]=min(low[v], low[w]);
            //cout<<"After complete dfs low["<<v<<"]="<<low[v]<<" is min of this and "<<w<<"\n";
            if(low[w]==pre[w])
            {
                //cout<<"Bridge is "<<v<<" and "<<w<<endl;
                bridges++;
            }
        }
        else
        if(w!=u)
        {
            //cout<<w<<" is not a neigh of "<<v<<" and is not a parent "<<u<<endl;
            low[v]=min(low[v], pre[w]);
            //cout<<"So low["<<v<<"]="<<low[v]<<" min of this and "<<w<<endl;
        }
    }
}
int main ()
{
    memset(low, -1, sizeof low);
    memset(pre, -1, sizeof pre);
    cin>>n>>m;
    for(int i=0; i<m; ++i)
    {
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for(int j=0; j<n; ++j)
    {
        if(pre[j]==-1)
        {
            dfs(j, j);
        }
    }
    cout<<bridges<<endl;
    return 0;
}
/*
8 9
0 1
0 4
4 5
1 5
5 6
2 6
2 7
6 7
7 3
*/
