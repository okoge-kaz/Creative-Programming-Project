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
// https://atcoder.jp/contests/abc166/tasks/abc166_e
int main(){
    int N; cin >> N;
    vector<ll>A(N);
    for(int i=0;i<N;i++) cin >> A[i];
    ll ans = 0LL;

    // i < j のとき
    // j - i = A[j] + A[i]
    // j - A[j] = A[i] + i
    map<ll,ll>B; map<ll,ll>C;
    for(int i=0;i<N;i++){
        B[A[i]+(i+1)]++;
        C[(i+1)-A[i]]++;
    }
    for(auto[value,cnt]:B){
        ans += (cnt * C[value]);
    }
    // このようにして成立するのは、A[i]!=0だから、そうでないとA[i]+(i+1) == (i+1)-A[i]が成立してしまいとても厄介
    cout << ans << endl;
}