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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll>a(N);
    for(int i=0;i<N;i++) cin >> a[i];
    
    ll cnt = 0;
    int r = 1;
    ll crt = 0;
    // [l,r)
    for(int l=0;l<N;l++){
        while(crt < K && r <= N){
            crt += a[r-1];
            r++;
        }
        if(crt < K) break;
        cnt += (N-r+2);// 余分にr++されているので
        crt -= a[l];
        if(l==r) r++;
    }
    cout << cnt << endl;
}