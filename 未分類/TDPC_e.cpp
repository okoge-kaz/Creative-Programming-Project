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
using lll = __int128_t;
// vector dp(11000,vector(2,vector<ll>(100,-1)));

vector<vector<vector<ll>>>dp;
// 初期値を設定することを忘れないように
string N; int D; int n;
ll rec(int d=0,bool smaller=false,int remain=0){
    if(d > n) return 0;
    if(d==n && remain == 0) return 1;// 初期値の設定
    ll &res = dp[d][(int)smaller][remain];
    if(res >= 0) return res;

    res = 0;
    if(smaller){
        // 現時点で小さい
        for(int i=0;i<10;i++){
            res += rec(d+1,true,(remain+i)%D);
            res %= MOD;
        } 
    }
    else{
        // 現時点ではイコール
        int digit = N[d]-'0';
        for(int i=0;i<digit;i++){
            res += rec(d+1,true,(remain+i)%D);
            res %= MOD;
        }
        res += rec(d+1,false,(remain+digit)%D);
        res %= MOD;
    }
    return res;
}
int main(){
    dp.resize(11000,vector<vector<ll>>(2,vector<ll>(100,-1)));
    cin >> D >> N;
    n = (int)N.size();
    
    cout << rec(0,false,0)-1 << endl;
}