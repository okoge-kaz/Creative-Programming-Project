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
    int N;
    cin >> N;
    vector<ll>A(N); for(ll &a:A) cin >> a;
    vector<ll>sum(N+1); for(int i=0;i<N;i++) sum[i+1] = sum[i] + A[i];
    vector<ll>max_A(N); ll last_max = 0LL;
    for(int i=0;i<N;i++){
        chmax(last_max,A[i]);
        max_A[i] = last_max;
    } 

    vector<ll>accumulation_A(N+1);
    for(int i=1;i<=N;i++) accumulation_A[i] = accumulation_A[i-1] + sum[i];

    for(int i=0;i<N;i++){
        ll ans = accumulation_A[i+1];
        ans += (max_A[i])*(i+1);
        cout << ans << endl;
    }
}