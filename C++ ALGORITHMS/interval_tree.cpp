#include <cstdio>
#include <vector>
using namespace std;

struct MyTree
{
    vector<int> Save_Tree;
    void Make_Tree(int Size)
    {
        int Size1;
        Size1=Size;
        Save_Tree.clear();
        for(int i=0;i<2*Size1+5;++i)
        {
            Save_Tree.push_back(0);
        }
    }
    int Print_Interval(int from, int to, int curri, int currj, int now)
    {
        if(to<curri || from>currj)
        {
            return 0;
        }
        if(from<=curri && to>=currj)
        {
            return Save_Tree[now];
        }
        int Left, Right;
        Left=Print_Interval(from, to, curri, (curri+currj)/2, 2*now);
        Right=Print_Interval(from, to, (curri+currj)/2+1, currj, 2*now+1);
        return Left+Right;
    }
    void Change_Interval(int from, int to, int curri, int currj, int now, int vl)
    {
        if(to<curri || from>currj)
        {
            return;
        }
        if(curri==currj)
        {
            Save_Tree[now]+=vl;
            return;
        }
        Change_Interval(from, to, curri, (curri+currj)/2, 2*now, vl);
        Change_Interval(from, to, (curri+currj)/2+1, currj, 2*now+1, vl);
        Save_Tree[now]=Save_Tree[2*now]+Save_Tree[2*now+1];
    }
};

MyTree tree;
int n, what, a, b;

int main ()
{
    scanf("%d", &n);
    tree.Make_Tree(n);
    while(1)
    {
        scanf("%d", &what);
        if(what==0)
        {
            break;
        }
        if(what==1)
        {
            scanf("%d %d", &a, &b);
            tree.Change_Interval(a, a, 1, n, 1, b);
        }
        else
        {
            scanf("%d %d", &a, &b);
            printf("%d\n", tree.Print_Interval(a, b, 1, n, 1));
        }
    }
    return 0;
}
