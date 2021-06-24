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
// 素因数分解する関数
vector<pair<ll,ll>> prime_factorize(ll N){
    vector<pair<ll,ll>>res;
    for(ll i=2;i*i <= N;i++){
        if(N % i != 0) continue;
        ll num = 0;
        while(N % i == 0){
            num++;
            N /= i;// これで素数だけが取れる
        }
        res.push_back({i,num});
    }
    if(N != 1) res.push_back({N,1});//素数の時
    return res;
}
int main(){
    ll N; cin >> N;
    auto vec = prime_factorize(N);
    ll tmp = 0;
    for(auto[value,cnt]:vec) tmp += cnt;
    int ans = 0;
    ll n = 1;
    while(tmp > n){
        n *= 2;
        ans++;
    }
    cout << ans << endl;
}