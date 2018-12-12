#include <cstdio>
#include <vector>
#define debug printf("OKEY\n")
const int ssize=1024;

int n;
int a[ssize];

void mergeHelp(int l, int mid, int r)
{
    int arr1[ssize/2], arr2[ssize/2], sarr1=mid-l+1, sarr2=r-mid;
    for(int i=0; i<sarr1; ++i)
    {
        arr1[i]=a[i+l];
    }
    for(int i=0; i<sarr2; ++i)
    {
        arr2[i]=a[mid+1+i];
    }
    int i=0, j=0, k=l;
    while(i<sarr1 && j<sarr2)
    {
        if(arr1[i]<=arr2[j])
        {
            a[k]=arr1[i];
            i++;
        }
        else
        {
            a[k]=arr2[j];
            j++;
        }
        k++;
    }
    while(i<sarr1)
    {
        a[k]=arr1[i];
        k++;
        i++;
    }
    while(j<sarr2)
    {
        a[k]=arr2[j];
        k++;
        j++;
    }
}

void mergeMain(int ll, int rr)
{
    int mmid;
    if(ll<rr)
    {
        mmid=(ll+rr)/2;
        mergeMain(ll, mmid);
        mergeMain(mmid+1, rr);
        mergeHelp(ll, mmid, rr);
    }
}

int main ()
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &a[i]);
    }
    mergeMain(0, n-1);
    for(int i=0; i<n; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
