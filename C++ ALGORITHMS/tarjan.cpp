#include <bits/stdc++.h>

#define File freopen("tarjan.txt", "r", stdin)

using namespace std;

const int nMax=1<<10;

int n, m, a, b, curr;

vector<int> v[nMax];
int scc[nMax], dfsnumb[nMax], low[nMax];
stack<int> st;
int num=0, numb_scc=0;

void init()
{
   memset(scc, -1, sizeof(scc));
   memset(dfsnumb, -1, sizeof dfsnumb);
   memset(low, -1, sizeof(low));
}

void tarjan(int u)
{
   dfsnumb[u]=low[u]=(num++);
   st.push(u);
   for(int kk=0; kk<(int)v[u].size(); ++kk)
   {
      curr=v[u][kk];
      if(scc[curr]==-1)
      {
         if(dfsnumb[curr]==-1)
         {
            tarjan(curr);
         }
         low[u]=min(low[u], low[curr]);
      }
   }
   if(low[u]==dfsnumb[u])
   {
      while(scc[u]!=numb_scc)
      {
         printf("%d ", st.top());
         scc[st.top()]=numb_scc;
         st.pop();
      }
      printf("\n");
      numb_scc++;
   }
}

int main ()
{
   File;
   scanf("%d %d", &n, &m);
   for(int i=0; i<m; ++i)
   {
      scanf("%d %d", &a, &b);
      v[a].push_back(b);
   }
   init();
   tarjan(0);
   return 0;
}
