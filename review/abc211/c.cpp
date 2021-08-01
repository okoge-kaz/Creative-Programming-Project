#include <bits/stdc++.h>
#include <atcoder/all>
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
using mint = modint1000000007;
int main(){
    // 類題は競プロ典型90の008
    // 競プロ典型の解き直しをした方がよいかも
    string S; cin >> S;
    int n = (int)S.size();
    string c = "chokudai";// このようなDPにできるのはこの文字列に同じ文字がないから
    vector<vector<mint>>dp(n+1,vector<mint>(9));
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=8;j++){
            // なにもしないときのスライドがあるので注意
            dp[i+1][j] += dp[i][j];// 下線をひかないとき
            if(j<8 && S[i]==c[j]){
                // このようにしないと index is out of rangeになる
                dp[i+1][j+1] += dp[i][j];
            }
        }
    }
    cout << dp[n][8].val() << endl;
}