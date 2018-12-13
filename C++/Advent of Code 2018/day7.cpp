#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> neigh[26];
int toDo[26];
bool used[26], in[26];

int main () {
    string line;
    while(getline(cin, line)) {
        neigh[line[5]-65].push_back(line[36]-65);
        toDo[line[36]-65]++;
        used[line[36]-65]=used[line[5]-65]=1;
    }

    bool fl;
    int idx;
    string ans="";

    while(1) {
        fl=false;
        for(int i=0; i<26; ++i) {
            if(toDo[i]==0 && used[i] && !in[i]) {
                fl=true;
                idx=i;
                break;
            }
        }
        if(!fl) break;
        in[idx]=1;
        ans+=('A'+idx);
        for(int i:neigh[idx]) toDo[i]--;
    }
    cout<<ans<<endl;
    return 0;
}