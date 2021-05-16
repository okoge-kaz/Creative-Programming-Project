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
    int N;
    cin >> N;
    vector dp(4, vector(1 << 5, 0));
    // vector<vector< の省略形 C++17以降
    // dp[i][j] = i人まで採用、能力値の採用状況 j
    dp[0][0] = INF;
    while(N--){
        auto dp2 = dp;
        for(int x=0;x<5;x++){
            int A;
            cin >> A;
            for(int j=0;j<3;j++) for(int k=0;k<(1<<5);k++){
                if( k & 1 << x) chmax(dp2[j][k], min(dp2[j][k^1 << x], A));
                // 0 <= k < (1<<5)よりbit演算, 
            }
        }
        for(int j=0;j<3;j++) for(int k=0;k<(1<<5);k++){
            chmax(dp[j+1][k], dp2[j][k]);
        }
    }
    cout << dp.back().back() << endl;
}