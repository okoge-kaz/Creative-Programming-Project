#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
const long long INF = 1LL << 60;
const int inf = (1 << 30);
const ll mod = 998244353;
const ll MOD = 1000000007;
const ld PI = acos(-1.0L);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    // このタイプの問題は解いたことがなかった
    ll N, K;
    cin >> N >> K;
    vector<ll>c(N+1);
    for(int i=2;i<=N;i++){
        if(c[i]!=0) continue;
        // ここは素数の定数倍のところにすべて++する。
        // エラトステネスの篩の要領
        for(int j=i;j<=N;j+=i){// j+=iなことに注意
            c[j]++;
        }
    }
    
    ll cnt = 0;
    for(int i=2;i<=N;i++) if(c[i] >= K) cnt++;
    cout << cnt << endl;
}