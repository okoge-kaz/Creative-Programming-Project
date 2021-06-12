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
int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    int N; cin >> N;
    string s1, s2; cin >> s1 >> s2;
    vector<ll>dp(N); ll ans = 0;
    for(int i=0;i<N;){
        if(s1[i]==s2[i]){
            //縦置き
            if(i==0){
                dp[i] = 3; ans = dp[i]; i++;
            } 
            else{
                if(s1[i-1]==s2[i-1]){
                    dp[i] = dp[i-1] * 2 % MOD;
                    ans = dp[i]; i++;
                } 
                else{
                    dp[i] = dp[i-1];
                    ans = dp[i]; i++;
                } 
            }
        }
        else{
            //横置き
            if(i==0){
                dp[i+1] = dp[i] = 6; ans = dp[i]; i+=2;
            } 
            else{
                if(s1[i-1]==s2[i-1]){
                    dp[i+1] = dp[i] = 2 * dp[i-1] % MOD;
                    ans = dp[i]; i+=2;
                }
                else{
                    dp[i+1] = dp[i] = 3 * dp[i-1] % MOD;
                    ans = dp[i]; i+=2;
                }
            }
        }
    }
    cout << ans << endl;
}