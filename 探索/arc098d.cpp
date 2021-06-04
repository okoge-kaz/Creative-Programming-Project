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
    // input
    int N; cin >> N;
    vector<ll>A(N); for(ll &a:A) cin >> a;
    // cumulative sum
    vector<ll>sum(N+1), xor_sum(N+1);
    for(int i=0;i<N;i++){
        sum[i+1] = sum[i] + A[i];
        xor_sum[i+1] = xor_sum[i] ^ A[i];
    }

    ll cnt=0;
    for(int l=1;l<=N;l++){
        // ok か ng のうち答えになるokの方は解が存在するようにする
        int ok = l; int ng = N+1;// okではない方は解が存在する範囲+1
        while(abs(ng-ok)>1){
            int mid = (ok+ng)/2;
            ll sum_tmp = sum[mid] - sum[l-1];// [l,mid]
            ll xor_tmp = xor_sum[mid] ^ xor_sum[l-1];// [l,mid]
            if(xor_tmp==sum_tmp) ok = mid;
            else ng = mid;
        }
        if(ok>=l)cnt += (ok-l+1);
    }
    cout << cnt << endl;
}