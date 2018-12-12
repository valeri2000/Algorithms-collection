#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
 
struct lists 
{
    int start;
    int end;
    int distance;
};

lists a[1024];
int parent[256], n, m;
int length_a=0;
int outputCost=0;
int selectedEdges;
 
bool cmp(lists p, lists q)
{
    return p.distance<q.distance;
}
 
void fill()
{
    for(int i=0;i<256;++i)
    {
    	parent[i]=i;
	}
}
 
int parentOf(int n)
{
    if(n==parent[n]) 
    {
    	return n;
	}
    return parent[n]=parentOf(parent[n]);
}
 
int main ()
{
    scanf("%d %d", &n, &m);
    fill();
    for(int i=1;i<=m;++i) 
	{
        int v1, v2, dist;
        scanf("%d %d %d", &v1, &v2, &dist);
        a[length_a].start=v1;
        a[length_a].end=v2;
        a[length_a++].distance=dist;
    }
    sort(a, a+length_a, cmp);
    selectedEdges=n-1;
    for(int i=0;i<length_a && selectedEdges;++i) 
	{
        int p=parentOf(a[i].start);
        int q=parentOf(a[i].end);
        //printf("start=%d end=%d p=%d q=%d , dist=%d\n", a[i].start, a[i].end, p, q, a[i].distance);
        if(p!=q) 
		{
            parent[p]=q;
            selectedEdges--;
            outputCost+=a[i].distance;
        }
    }
    printf ("%d\n", outputCost);
    return 0;
}
/*
9 14
0 1 4
7 0 8
1 7 11
2 1 8
8 2 2
8 7 7
6 7 1
8 6 6
6 5 2
5 2 4
3 2 7
4 3 9
5 3 14
5 4 10
*/
