#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
const long long INF = 1LL << 60;
const int inf = (1 << 30);
const ll mod = 10007;
const ll MOD = 1000000007;
const ld PI = acos(-1.0L);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int trib[1100000];
int main(){
    int n;
    cin >> n;
    if(n<=3){
        if(n==1) cout << 0 << endl;
        else if(n==2) cout << 0 << endl;
        else cout << 1 << endl;
    }
    else{
        trib[1] = 0, trib[2] = 0, trib[3] = 1;
        for(int i=4;i<=n;i++){
            trib[i] = trib[i-1] + trib[i-2] + trib[i-3];
            trib[i] %= mod;
        }
        cout << trib[n] << endl;
    }
}