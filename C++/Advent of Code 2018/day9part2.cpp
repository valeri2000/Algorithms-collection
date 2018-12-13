#include <iostream>
#include <list>

using namespace std;

typedef list<long long>::iterator it;

const int n=435, m=7118400;

list<long long> a;
long long points[437];

it next(it curr) {
    return ++curr==a.end()?a.begin():curr;
}

it prev(it curr) {
    return curr==a.begin()?--a.end():--curr;
}

int main() {
    a.push_back(0);
    it curr=a.begin(), smth;
    for(int i=1; i<m; ++i) {
        if(i%23) {
            curr=next(curr);
            curr=next(curr);
            curr=a.insert(curr, i);       
         } else {
            for(int j=0; j<7; ++j) curr=prev(curr);
            points[i%n]+=(i+*curr);
            curr=a.erase(curr);
        }
    }

    long long xmax=0;
    for(int i=0; i<n; ++i) xmax=max(xmax, points[i]);
    cout<<xmax<<'\n'; 
    return 0;
}