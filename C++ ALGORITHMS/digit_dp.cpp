#include <bits/stdc++.h>

#define endl '\n'
#define left jhghajkhja
#define right oauighgajk
#define prev aioghajga
#define next ioyhjhfajasj
#define y0 iuadoghasdgj
#define y1 taklahgjkla
#define remainder pogjuakllhga
#define pow pajklgaklha
#define pow10 iopuioadjlgkah
#define div aljghajkghak
#define distance gkuftgjasgfjh
#define uppercase ifyhasjkhakjfas

//#define floor hjakjhaja
//#define time ashjlahjka
//#define double_t double
//#define tm kahjflahaajk

using namespace std;

const int MOD = (1e9) + 7;

template <int MOD>
struct mod_int {
private:
    int a;
    int fpow(int a, int b) {
        if(a==0) return 0%MOD;
        if(b==0) return 1%MOD;
        int p=fpow(a,b>>1);
        p=(p*1ll*p)%MOD;
        if(b&1) return (p*1ll*a)%MOD;
        else return p;
    }
public:
    mod_int(): a(0%MOD) {}
    mod_int(int x) {
        (*this).a=x%MOD;
    }
    int &value() {
        return a;
    }
    void operator +=(mod_int x) {
        (*this).a=((*this).a+x.a)%MOD;
    }
    void operator -=(mod_int x) {
        (*this).a=((*this).a-x.a+MOD)%MOD;
    }
    void operator *=(mod_int x) {
        (*this).a=((*this).a*1ll*x.a)%MOD;
    }
    void operator /=(mod_int x) {
        (*this).a=((*this).a*1ll*fpow(x.a,MOD-2))%MOD;
    }
    mod_int operator +(mod_int x) {
        mod_int y(*this);
        y+=x;
        return y;
    }
    mod_int operator -(mod_int x) {
        mod_int y(*this);
        y-=x;
        return y;
    }
    mod_int operator *(mod_int x) {
        mod_int y(*this);
        y*=x;
        return y;
    }
    mod_int operator /(mod_int x) {
        mod_int y(*this);
        y/=x;
        return y;
    }
    bool operator ==(const mod_int &x) const {
        return a==x.a;
    }
    bool operator <(const mod_int &x) const {
        return a<x.a;
    }
    bool operator <=(const mod_int &x) const {
        return a<=x.a;
    }
    bool operator >(const mod_int &x) const {
        return a>x.a;
    }
    bool operator >=(const mod_int &x) const {
        return a>=x.a;
    }
};

typedef mod_int < MOD > mint;

int m,d;
string a,b;
int n;
bool used[2048][2048][2][2];
mint state[2048][2048][2][2];

mint recurse(int pos, int remainder, bool f1, bool f2) {
    if(pos==n) {
        if(remainder==0) return 1;
        else return 0;
    }
    if(used[pos][remainder][f1][f2]) return state[pos][remainder][f1][f2];
    mint ans=0;
    int i;
    for(i=((pos==0) ? 1 : 0);i<=9;i++) {
        if((pos&1)==0 && i==d) continue;
        if(pos&1 && i!=d) continue;
        if((f1==true || (f1==false && i>=a[pos]-'0')) && (f2==true || (f2==false && i<=b[pos]-'0'))) ans+=recurse(pos+1,(remainder*10+i)%m,f1|(i>a[pos]-'0'),f2|(i<b[pos]-'0'));
    }
    used[pos][remainder][f1][f2]=true;
    state[pos][remainder][f1][f2]=ans;
    return ans;
}

int main() {
    freopen("i1.txt", "r", stdin);
    //freopen("test.txt","r",stdin);
    //freopen(IN.c_str(),"r",stdin);
    //freopen(OUT.c_str(),"w",stdout);
    //fread(buff,1,sizeof(buff),stdin);
    
    cin>>m>>d;
    cin>>a>>b;
    n=max((int)(a.size()),(int)(b.size()));
    reverse(a.begin(),a.end());
    while((int)(a.size())<n) a.push_back('0');
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    while((int)(b.size())<n) b.push_back('0');
    reverse(b.begin(),b.end());
    cout<<a<<" "<<b<<endl;
    printf("%d\n", recurse(0,0,0,0).value());
    
    //fprintf(stderr, "Time: %d ms\n", (int)(clock()*1000.0/CLOCKS_PER_SEC));

    return 0;
}