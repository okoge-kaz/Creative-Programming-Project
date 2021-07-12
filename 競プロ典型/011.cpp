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
using lll = __int128_t;
int main(){
    int N; cin >> N;
    vector<pair<int,int>>D(N); vector<int>C(N); vector<ll>S(N);
    for(int i=0;i<N;i++){ cin >> D[i].first >> C[i] >> S[i] ; D[i].second = i; }
    sort(D.begin(),D.end());
    // sortしないとDPがおかしくなる

    vector<vector<ll>>dp(N+1,vector<ll>(5100));
    // dp[i][j]: i個目の仕事までみてj日に終了する仕事がある
    for(int i=0;i<N;i++){
        for(int d=0;d<=5000;d++){
            int id = D[i].second;
            // 何もしない
            chmax(dp[i+1][d],dp[i][d]);
            if(d+C[id]<=5000 && d+C[id]<=D[i].first ){// 配列からはみ出ない＋締め切りまで
                chmax(dp[i+1][d+C[id]],dp[i][d]+S[id]);
            }
        }
    }
    ll ans = 0;
    for(int d=0;d<=5000;d++) chmax(ans,dp[N][d]);
    cout << ans << endl;
}