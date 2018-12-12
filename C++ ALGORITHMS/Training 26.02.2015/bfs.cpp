#include <cstdio>
#include <queue>
using namespace std;

int n, m, a, b, st, x, finish;
int BestWay[1024];
bool A[1024][1024], used[1024];
queue<int> q;

int main ()
{
	scanf("%d %d", &n, &m);
	for(int i=0;i<m;++i)
	{
		scanf("%d %d", &a, &b);
		A[a][b]=1;
		A[b][a]=1;
	}
	scanf("%d", &st);
	q.push(st);
	used[st]=1;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(int i=1;i<=n;++i)
		{
			if(A[x][i]==1 && used[i]==0)
			{
				q.push(i);
				used[i]=1;
				BestWay[i]=x;
			}
		}
	}
	finish=n;
	printf("%d", finish);
	x=BestWay[finish];
	while(x!=st)
	{
		printf(" %d", x);
		x=BestWay[x];
	}
	printf(" %d\n", st);
	return 0;
}
/*
7
7
1 2
1 3
3 5
2 4
5 6
4 7
6 7
*/
