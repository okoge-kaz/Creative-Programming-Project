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
    int N, K;
    cin >> N >> K;

    // 愚直に計算しようとするとO(N^3)かかる
    // これを制限時間内に終わらせるには、O(N) or O(N log(N))
    ll cnt = 0;
    vector<ll>num(K,0);// 後で掛け算をするときにオバーフローしないようにあえて long long
    for(int i=1;i<=N;i++){
        num[i % K]++;// num[x] = (Kで割ってx余る数がNまでに何個あるか)
    }
    ll res = 0;
    for(int a=0;a<K;a++){
        int b = (K-a) % K;
        int c = (K-a) % K;
        if((b + c)%K!=0 ) continue;
        res += num[a] * num[b] * num[c];
    }
    // この問題のポイントは、あまりに着目することで他の変数が一意に決まるということ
    cout << res << endl;
}