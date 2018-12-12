#include <iostream>
using namespace std;
struct node
{
    int key;
    node *l;
    node *r;
};
typedef node* decc;
decc tree;
string Input;
int M[32];
int main ()
{
    cin>>Input;
    for(int i=0;i<Input.size();++i)
    {
        M[Input[i]-'A']++;
    }
    return 0;
}
