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
ll N,A,B; vector<ll>h;
bool check(ll x){
    vector<ll>tmp = h;
    for(int i=0;i<N;i++) tmp[i] = max((lll)0,tmp[i]-((lll)B*x));// B*xがオーバーフローする恐れあり
    ll cnt = 0;
    for(int i=0;i<N;i++){
        if(tmp[i]<=0) continue;
        cnt += (tmp[i]%(A-B)==0) ? tmp[i]/(A-B) : tmp[i]/(A-B) + 1LL;
    }
    return ( x >= cnt);
}
int main(){
    cin >> N >> A >> B;
    h.resize(N); for(ll &e:h) cin >> e;
    ll ng = 0; ll ok = INF;
    while(abs(ok-ng)>1){
        ll mid = (ok+ng)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}