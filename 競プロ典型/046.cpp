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
int main(){
    int N;
    cin >> N;
    vector<ll> A(N),B(N),C(N);
    for(int i=0;i<N;i++) cin >> A[i];
    for(int i=0;i<N;i++) cin >> B[i];
    for(int i=0;i<N;i++) cin >> C[i];

    map<ll,ll>a,b,c;
    for(int i=0;i<N;i++) a[A[i]%46]++;
    for(int i=0;i<N;i++) b[B[i]%46]++;
    for(int i=0;i<N;i++) c[C[i]%46]++;

    ll ans = 0;
    for(auto[a_value,a_cnt]:a) for(auto[b_value,b_cnt]:b) for(auto[c_value,c_cnt]:c){
        if((a_value + b_value + c_value) % 46 == 0){
            ans += a_cnt * b_cnt * c_cnt;
        }
    }
    cout << ans << endl;
}