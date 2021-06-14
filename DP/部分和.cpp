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
int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    // 部分和問題は動的計画法で解けることが知られているが、bitsetを用いるとさらに高速に解くことができる
    int N, K; cin >> N >> K;
    vector<int>A(N); for(int i=0;i<N;i++) cin >> A[i];
    // DPの場合 計算量O(NK)
    vector<vector<int>>dp(N+1,vector<int>(K+1,-1));
    dp[0][0] = 1;
    for(int i=0;i<N;i++){
        for(int j=0;j<=K;j++){
            if(dp[i][j]==1){
                dp[i+1][j] = 1;
                if(j+A[i]<=K) dp[i+1][j+A[i]] = dp[i][j];
            }
        }
    }
    // bitsetの場合 O(NK/32)
    

}