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
bool check(ll mid,vector<ll>&v,ll x){
    if(v[mid] <= x) return true;
    else return false;
}
template<typename T>
ll below_bound(vector<T>&vec,T value){
    // value以下になるもので最大のidを取得する(0-index)
    ll ok = -1; ll ng = (ll)vec.size();
    while(abs(ok-ng)>1){
        ll mid = (ok+ng)/2;
        if(check(mid,vec,value)) ok = mid;
        else ng = mid;
    }
    return ok;// 1つもない時は-1を返す
}
int main(){
    ll N; cin >> N;
    vector<ll>A(N); for(ll &e:A) cin >> e;
    sort(A.begin(),A.end());
    vector<ll>sum(N+1,0); for(int i=0;i<N;i++) sum[i+1] = sum[i] + A[i];

    int id = 0;
    for(int i=N-1;i>=0;i--){
        id = i;
        if(2*sum[i]<A[i])break;
    }
    cout << N - id << endl;
}