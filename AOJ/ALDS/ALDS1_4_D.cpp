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
// allocation 問題として有名らしい
ll n,k; vector<ll>w;
bool check(ll p){
    ll crr = 0; int cnt = 1;
    for(int i=0;i<n;i++){
        if(crr + w[i] > p){
            if(w[i] <= p){ crr = w[i]; cnt++;}
            else return false;
        }
        else crr += w[i];
    }
    return cnt <= k;
}
int main(){
    // allocation
    cin >> n >> k;
    w.resize(n);
    for(ll &e:w) cin >> e;
    ll ok = INF; ll ng = 0;
    while(abs(ok-ng)>1){
        ll mid = (ok + ng)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}