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
using lll = __int128_t;
int main(){
    int N; cin >> N;
    vector<ll>A(N); for(ll &e:A) cin >> e;
    vector<ll>sum(N+1); for(int i=0;i<N;i++) sum[i+1] = sum[i] + A[i];
    ll ans = INF;
    // sum[1] > 0
    ll cost = 0;
    if(sum[1] <= 0){ cost += abs(sum[1])+1; sum[1] = 1;}
    for(int i=2;i<=N;i++){
        sum[i] = sum[i-1] + A[i-1];
        if(sum[i]*sum[i-1] < 0) continue;
        if(sum[i-1] > 0){
            // sum[i] < 0 とする
            cost += abs(sum[i]) + 1;
            sum[i] = -1;
        }
        else{
            // sum[i] > 0 とする
            cost += abs(sum[i])+1;
            sum[i] = 1;
        }
    }
    chmin(ans,cost);
    // sum[1] < 0
    cost = 0;
    sum.assign(N+1,0);
    for(int i=0;i<N;i++) sum[i+1] = sum[i] + A[i];
    if(sum[1] >= 0){ cost += abs(sum[1])+1; sum[1] = -1;}
    for(int i=2;i<=N;i++){
        sum[i] = sum[i-1] + A[i-1];
        if(sum[i]*sum[i-1] < 0) continue;
        if(sum[i-1] > 0){
            // sum[i] < 0 とする
            cost += abs(sum[i]) + 1;
            sum[i] = -1;
        }
        else{
            // sum[i] > 0 とする
            cost += abs(sum[i])+1;
            sum[i] = 1;
        }
    }
    chmin(ans,cost);
    cout << ans << endl;
}