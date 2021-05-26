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
using mint = modint998244353;
int main(){
    int N; cin >> N;
    vector A(N,0LL); for(auto &a:A) cin >> a;
    sort(A.begin(),A.end());
    // 全然わからなかった
    mint ans = 0LL;
    for(int i=0;i<N;i++) ans += A[i] * A[i];
    // 以下の計算の部分が通常通りにすると計算量が 2^Nを計算することのせいで o(N)になる
    vector<mint>B(N+1);
    for(int i=N-1;i>=0;i--){
        B[i] = (B[i+1]*2) + A[i];
    }

    for(int i=0;i<N;i++) ans += A[i] * B[i+1];
    cout << ans.val() << endl;
}