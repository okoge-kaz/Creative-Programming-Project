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
int H,W;
vector<vector<ll>>dp; vector<vector<bool>>seen;
vector<string> A;

ll min_max(int x,int y){
        // ラムダ式のそとにあるものは、通常の関数とどうように参照できない
        if(seen[y][x]) return dp[y][x];
        seen[y][x] = true;
        if(y==H-1 && x == W-1) return dp[y][x] = 0;//ここが開始点
        if((y+x)%2==0){
            // takahashi
            dp[y][x] = -INF;
            if(y+1<H) chmax(dp[y][x],min_max(x,y+1)+(A[y+1][x] == '+' ? 1 : -1));//この書き方は上手い
            if(x+1<W) chmax(dp[y][x],min_max(x+1,y)+(A[y][x+1] == '+' ? 1 : -1));
            return dp[y][x];
            // min-max法は、最後の点から遡っていく
        }
        else{
            dp[y][x] = INF;
            // dpは takahashi - aoki なので、aokiが'+'だったら - マイナスであることに注意
            if(y+1<H) chmin(dp[y][x],min_max(x,y+1)-(A[y+1][x] == '+' ? 1 : -1));
            if(x+1<W) chmin(dp[y][x],min_max(x+1,y)-(A[y][x+1] == '+' ? 1 : -1));
            return dp[y][x];
        }
}

int main(){
    cin >> H >> W;
    A.resize(H);
    for(int i=0;i<H;i++) cin >> A[i];

    // min-max法を用いた、DP
    dp.resize(H,vector<ll>(W,0LL));// (takahashi) - (aoki)を記録
    seen.resize(H,vector<bool>(W,false));

    ll opt = min_max(0,0);
    if(0 < opt) cout << "Takahashi" << endl;
    else if(opt==0) cout << "Draw" << endl;
    else cout << "Aoki" << endl;
}