#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> neigh[26], avail;
int toDo[26];
bool used[26], in[26];

const int WORKERS=5, BASE=60;

struct Worker {
    int timeLeft, job=26;
    bool busy;
}; Worker a[WORKERS];

int main () {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string line;
    while(getline(cin, line)) {
        neigh[line[5]-65].push_back(line[36]-65);
        toDo[line[36]-65]++;
        used[line[36]-65]=used[line[5]-65]=1;
    }

    int time=-1;
    bool fl;

    do {
        for(int i=0; i<26; ++i) {
            if(toDo[i]==0 && used[i] && !in[i]) {
                avail.push_back(i);
            }
        }
        if(!(int)avail.size()) {
            fl=false;
            time++;
            for(int i=0; i<WORKERS; ++i) {
                if(a[i].busy) {
                    fl=true;
                    a[i].timeLeft--;
                    a[i].timeLeft=max(0, a[i].timeLeft);
                    if(!a[i].timeLeft) {
                        a[i].busy=false;
                        for(int j:neigh[a[i].job]) toDo[j]--;
                        continue;
                    }
                }
            }
            if(!fl) break;
        }
        reverse(avail.begin(), avail.end());
        while((int)avail.size()) {
            time++;
            for(int i=0; i<WORKERS; ++i) {
                if(!a[i].busy) {
                    if(!(int)avail.size()) continue;
                    a[i].busy=true;
                    a[i].job=avail.back();
                    a[i].timeLeft=avail.back()+BASE;
                    in[avail.back()]=1;
                    avail.pop_back();
                } else {
                    a[i].timeLeft--;
                    a[i].timeLeft=max(0, a[i].timeLeft);
                    if(!a[i].timeLeft) {
                        a[i].busy=false;
                        for(int j:neigh[a[i].job]) toDo[j]--;
                        if(!(int)avail.size()) continue;
                        a[i].busy=true;
                        a[i].job=avail.back();
                        a[i].timeLeft=avail.back()+BASE;
                        in[avail.back()]=1;
                        avail.pop_back();
                    }
                }
            }
        }
    } while(1);
    cout<<time<<'\n';
    return 0;
}