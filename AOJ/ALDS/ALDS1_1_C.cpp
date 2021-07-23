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
bool is_prime(ll num){
    if(num==1) return false;
    for(ll i=2;i*i<=num;++i){
        if(num%i==0) return false;
    }
    return true;
}
int main(){
    int n; cin >> n;
    int cnt = 0;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        if(is_prime(num)) cnt++;
    }
    cout << cnt << endl;
}