#include <bits/stdc++.h>
#include <atcoder/all>
#define _GLIBCXX_DEBUG
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef long double ld;
const long long INF = 1LL << 60;
const int inf = (1 << 30);
const ll mod = 998244353;
const ll MOD = 1000000007;
const ld PI = acos(-1.0L);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using mint = modint998244353;
int main(){
    ll N, K;
    cin >> N >> K;
    vector<int>L(K),R(K);
    for(int i=0;i<K;i++) cin >> L[i] >> R[i];

    // 愚直に解こうとすると計算量はO(N^2)
    // 本問は、DP高速化というものに分類される
    // modでわる系統の問題の場合は、mintを使いましょう
    vector<mint>dp(N,0), sdp(N+1,0);
    dp[0] = 1, sdp[1] = 1;// 初期値
    //sdp[1] = 1ここに注意
    for(int n=1;n<N;n++){
        for(int i=0;i<K;i++){
            int left = max(0,n-R[i]);//注意 left の方は、引く数が大きいためR[i]がくる
            int right = max(0,n-L[i]+1);// [l,r)にするため
            dp[n] += (sdp[right]-sdp[left]);
        }
        // 更新
        sdp[n+1] = sdp[n] + dp[n];
    }
    cout << dp[N-1].val() << endl;
}