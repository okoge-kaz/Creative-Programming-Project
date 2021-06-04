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
// 素因数分解した値をvectorで返す関数
vector<pair<ll,ll>>prime_factorize(ll N){
    // N を素因数分解する
    vector<pair<ll,ll>>res;
    for(ll a=2; a*a <= N;a++){
        if(N % a != 0) continue;
        ll ex = 0;// aの指数
        // 割れる限り割り続ける
        while(N % a==0){
            ++ex;
            N /= a;
        }
        res.push_back({a,ex});
    }
    // 最後に残った数について
    if(N != 1) res.push_back({N,1});// 1は素数でないので
    return res;
}
int main(){
    ll n; cin >> n;
    auto data = prime_factorize(n);
    cout << n << ":";
    for(auto[value,cnt]:data){
        for(int i=0;i<cnt;i++) cout << " " << value ;
    }
    cout << endl;
}