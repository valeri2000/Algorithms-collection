#include <bits/stdc++.h>

using namespace std;;

struct Node
{
    Node(int mykey, short mytype, Node* cparent)
    {
        this->key=mykey, this->type=mytype;
        this->parent=cparent;
    }
    int key;
    short type;
    Node* parent;
    vector<Node*> children;
};

int main ()
{
    Node* Tree=new Node(-1, 0, NULL);
    printf("parent - %d || type - %d\n", Tree->parent, Tree->type);
    Node* curr=new Node(1, 1, Tree);
    Tree->children.push_back(curr);
    return 0;
}
