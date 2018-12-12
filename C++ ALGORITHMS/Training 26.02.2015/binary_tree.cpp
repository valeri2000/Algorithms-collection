#include<iostream>
using namespace std;
struct node
{
    int key;
    node *l;
    node *r;
    node *p;
};
typedef node* decc;
void Add(int key);
void printf(decc current);
void way(int from, int to);
decc Tree;
void Add(int key)
{
    decc start;
    start=Tree;
    decc current1;
    while(1){
    if(start->key > key)
    {
        if(start->l!=NULL)
            start=start->l;
        else
        {
            current1=new node;
            current1->l=current1->r=NULL;
            current1->p=start;
            start->l=current1;
            current1->key=key;
            return;
        }
    }
    if(start->key < key)
    {
        if(start->r!=NULL)
            start=start->r;
        else
        {
            current1=new node;
            current1->l=current1->r=NULL;
            current1->p=start;
            start->r=current1;
            current1->key=key;
            return;
        }
    }
    }
}
void printf(decc current)
{
    if(current!=NULL)
    {
        cout<<current->key<<endl;
        printf(current->l);
        printf(current->r);
    }
}
decc findd(int key)
{
    decc start;
    start=Tree;
    while(start->key!=key){
    if(start->key > key)
    {
        if(start->l==NULL)
        {
            return 0;
        }
        else
            start=start->l;
    }
    else
    if(start->key < key)
    {
        if(start->r==NULL)
        {
            return 0;
        }
        else
            start=start->r;
    }
    }
    return start;
}
void GetWayFrom(int from, decc current)
{
    decc beg;
    beg = findd(from);
    cout<<beg->key;
    while(beg->key!=current->key)
    {
        beg=beg->p;
        cout<<" "<<beg->key;
    }
    cout<<endl;
}
void GetWayTo(int to, decc current)
{
    decc start;
    start=current;
    cout<<start->key;
    while(start->key!=to)
    {
        if(start->key < to)
        {
                start=start->r;
        }
        else
            start=start->l;
        cout<<" "<<start->key;
    }
}
int main ()
{
    Tree=new node;
    Tree->l=NULL;
    Tree->r=NULL;
    Tree->p=NULL;
    Tree->key=10;
    Add(6);
    Add(4);
    Add(1);
    Add(5);
    Add(7);
    Add(9);
    Add(15);
    Add(11);
    Add(13);
    Add(18);
    //printf(Tree);
    GetWayFrom(1, Tree);
    GetWayTo(5, Tree);
    return 0;
}
