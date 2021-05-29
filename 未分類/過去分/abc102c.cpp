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
int N;
vector<ll>A;
// 悲しさを求める関数
ll calc(ll b){
    ll res = 0;
    for(int i=0;i<N;i++){
        res += abs(A[i] -(b + i + 1LL) );
    }
    return res;
}
int main(){
    // input   
    cin >> N;
    A.resize(N);
    for(int i=0;i<N;i++) cin >> A[i];
    vector<ll>B(N);
    for(int i=0;i<N;i++) B[i] = A[i] - (i+1);
    // abs(A[i] - (b + i ))をしたくないので、iを引いておく
    sort(B.begin(),B.end());
    // bをBの中央値にすればよい
    if(N % 2 == 1){
        ll ans = 0;
        ll b = B[N/2];
        for(int i=0;i<N;i++) ans += abs(B[i] - b);
        cout << ans << endl;
    }
    else{
        ll tmp1 = 0, tmp2 = 0;
        ll b1 = B[N/2], b2 = B[N/2 - 1];
        for(int i=0;i<N;i++) tmp1 += abs(B[i] - b1), tmp2 += abs(B[i] - b2);
        cout << min(tmp1,tmp2) << endl;
    }
    // 解説を見ると中央値なのは明らかな気がするが、そもそもvector<ll>Bをつくるという発想がそもそもなかったのでそれも反省
}