#include <cstdio>
#include <algorithm>
using namespace std;
int n, srch, a[1024];
int BinSearch(int x)
{
    int l=0;
    int r=n-1;
    int mid;
    while(l<=r)
    {
        mid=l+r;
        mid=mid/2;
        if(a[mid]==x)
            return mid;
        else
        if(a[mid]>x)
            r=mid-1;
        else
            l=mid+1;
    }
    return -2;
}
int main ()
{
    scanf("%d", &n);
    for(int i=0;i<n;++i)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &srch);
    sort(a, a+n);
    printf("Position - %d\n", BinSearch(srch)+1);
    return 0;
}
