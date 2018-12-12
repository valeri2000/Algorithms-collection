#include <cstdio>
using namespace std;
int main ()
{
	int n, a, b, c, d;
	scanf("%d", &n);
	for(int i=0;i<n;++i)
	{
		scanf("%d %d %d %d", &a, &b, &c, &d);
	}
	if(n%2==1)
	{
		printf("%d\n", n-2);
	}
	else
	{
		printf("%d\n", n);
	}
	return 0;
}
