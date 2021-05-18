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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using mint = modint1000000007;
// ここでmodを定義

// nCkの nが n <= 10^7であったら、combination高層化手法を用いるべし
// nCk の nが大きいが、kは k <= 10^7 程度の場合は、愚直なcombinationの方が早い

mint combination(ll n, ll k){
    mint ans = 1;
    for(ll i=0;i<k;i++){
        ans *= (n-i);
        ans /= (i+1);
    }
    return ans;
}

ll comb(ll n, ll k){
    // combinationをするときは、kの方の値が小さくなることが確約されている方を使うように
    ll ans = 1;
    for(ll i=0;i<k;i++){
        ans *= (n-i);
        ans /= (i+1);
    }
    return ans;
}


int main(){
    ll n,k;
    mint ans = combination(n,k);
    cout << ans.val() << endl;
    //出力する際は、普通のlong longや int 型のように出力できるわけではない
    
}

// 詳細は https://drken1215.hatenablog.com/entry/2020/04/22/013400 