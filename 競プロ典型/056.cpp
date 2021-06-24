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
    int N,S; cin >> N >> S;
    vector<int>A(N),B(N);
    for(int i=0;i<N;i++) cin >> A[i] >> B[i];

    vector<vector<int>>dp(N+1,vector<int>(110000,-1));
    dp[0][0] = 1;
    for(int i=0;i<N;i++){
        for(int j=0;j<=S;j++){
            if(dp[i][j]==-1) continue;
            if(j+A[i]<=S) dp[i+1][j+A[i]] = 1;
            if(j+B[i]<=S) dp[i+1][j+B[i]] = 1;
        }
    }
    if(dp[N][S]==1){
        // 経路復元をDPでするのってどうするの？
        string ans;
        ll crr = S;
        for(int i=N;i>0;i--){
            if(crr - A[i-1] >= 0 && dp[i-1][crr-A[i-1]]==1){
                crr-= A[i-1];
                ans.push_back('A');
            }
            else{
                crr -= B[i-1];
                ans.push_back('B');
            }
        }
        reverse(ans.begin(),ans.end());
        cout << ans << endl;
    }
    else{
        cout << "Impossible" << endl;
    }
}