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
ll N,K; vector<ll>A;
bool check(ld x){
    ll cnt = 0;
    for(ll a:A) cnt += ceil(a/x)-1;
    if(cnt <= K) return true;
    else return false;
}
int main(){
    cin >> N >> K;
    A.resize(N); for(ll &e:A) cin >> e;
    //もしKが10^7オーダーならpriority_queueを用いた貪欲法で上手くできてしまう
    ld ok = inf; ld ng = 0;
    while(abs(ok-ng)>0.1){
        ld mid = (ok+ng)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    cout << (ll)ceil(ok) << endl;
}