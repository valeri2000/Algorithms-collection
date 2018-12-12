#include <cstdio>
#include <algorithm>
using namespace std;

int A[1024], n, target;
int l, r, mid;

int main ()
{
	scanf("%d %d", &n, &target);
	for(int i=0;i<n;++i)
	{
		scanf("%d", &A[i]);
	}
	sort(A, A+n);
	for(int i=0;i<n;++i)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
	l=0;
	r=n-1;
	while(l<=r)
	{
		mid=l+r;
		mid/=2;
		if(A[mid]==target)
		{
			printf("Found! Position=%d\n", mid+1);
			return 0;
		}
		else
		if(A[mid]>target)
		{
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	printf("Not found!\n");
	return 0;
}
