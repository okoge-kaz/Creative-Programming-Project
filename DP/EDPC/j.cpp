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
vector<int>a;
ld dp[301][301][301];
ld rec(int i,int j,int k){
    // i: 1個の皿の数, j:2個の皿の数, k:3個の皿の数
    if(dp[i][j][k] >= 0) return dp[i][j][k];//これで計算量を抑える
    if( i==0 && j==0 && k==0 ) return (ld)0.0;

    ld res = 0.0;
    if(i>0) res += rec(i-1,j,k) * (ld)i/(i+j+k);
    if(j>0) res += rec(i+1,j-1,k) * (ld)j/(i+j+k);
    if(k>0) res += rec(i,j+1,k-1) * (ld)k/(i+j+k);
    res += (ld)(N)/(i+j+k);
    return dp[i][j][k] = res;
}
int main(){
    // 期待値DPなど遷移の仕方が複雑な場合は、メモ化再帰で実装するべし
    cin >> N;
    a.resize(N);
    // 自己ループが存在する漸化式になるので、漸化式を解くことで、解決すべし
    for(int i=0;i<N;i++) cin >> a[i];
    int one = 0, two = 0, three = 0;
    for(int i=0;i<N;i++){
        if(a[i]==1) one++;
        if(a[i]==2) two++;
        if(a[i]==3) three++;
    }
    memset(dp,-1,sizeof(dp));// 初期化
    cout << fixed << setprecision(15) << rec(one,two,three) << endl;
}