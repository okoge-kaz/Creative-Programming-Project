#include <bits/stdc++.h>
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
ll dp[110][2][4]; string s; int n,K;
// for文を回すのもよいがメモ化再帰が最も実用的
ll rec(int d=0, bool smaller=false, int k=K){
    if(k==0) return 1;// もう自由に使える文字がないので
    if(d >= n) return 0;// 上からn桁決まっていたらもう何もないので

    ll &res = dp[d][(int)smaller][k];
    if(res > 0) return res;// 初期値ではない(すでに探索済み)
    // res = 0;// 探索済みではないとき ここいらないのでは

    if(smaller){
        // s よりも現時点で小さい
        res += rec(d+1,true,k);// 次の桁が0のとき
        // 0をつかったのでkの個数は変化なし
        res += rec(d+1,true,k-1)*9LL;// 次の桁が0以外のとき
    }
    else{
        if(s[d]=='0'){
            // ギリギリ今調べている桁より上はsと同じなので = smaller == false
            // 0以外ありえない
            res += rec(d+1,false,k);
        }
        else{
            res += rec(d+1,true,k);// 0をつかうとき
            res += rec(d+1,true,k-1) * (s[d]-'1');// 0,s[d]以外の数字をつかうとき
            // smaller == falseからsmallerになるにはs[d]をつかわない
            res += rec(d+1,false,k-1); // s[d]をつかうとき
        }
    }
    return res;// &参照型にしているのでdp[d][smaller][k]とする必要がない
}
int main(){
    cin >> s >> K;
    n = (int)s.size();
    cout << rec() << endl;
}