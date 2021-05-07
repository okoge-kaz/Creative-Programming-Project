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
ll H, N;
vector<pair<int,int>>AB;
ll dp[1100][21000];// dp[使用した魔法の番号][与えたダメージの総量]
int main(){
    cin >> H >> N;
    AB.resize(N);
    for(int i=0;i<N;i++){
        cin >> AB[i].first >> AB[i].second;
    }
    // この問題のように、貪欲に取る方法が不明でありかつ、制約条件が緩めのときはDP
    for(int i=0;i<1100;i++) for(int j=0;j<21000;j++) dp[i][j] = INF;
    // 個数制限なしナップザックの演習量が圧倒的に足らない
    dp[0][0] = 0;
    for(ll n=0;n<N;n++){
        for(ll h=0;h<=H;h++){
            chmin(dp[n+1][h],dp[n][h]);//何も選ばないとき
            chmin(dp[n+1][min(H, h+AB[n].first)],dp[n+1][h]+AB[n].second);
            // n+1 -> n+1の更新を作ることで個数制限なしナップザックが実現できる
        }
    }
    cout << dp[N][H] << endl;
}