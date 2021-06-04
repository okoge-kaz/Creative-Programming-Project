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
    ll N, P, Q; cin >> N >> P >> Q;
    vector A(N,0LL); for(ll &a:A) cin >> a;
    for(int i=0;i<N;i++) A[i] %= P;

    ll cnt = 0LL;
    // 定数倍を見積もる問題らしい、これは分からなかった
    for(int i=0;i<N;i++) for(int j=i+1;j<N;j++){
        for(int k=j+1;k<N;k++) for(int l=k+1;l<N;l++){
            for(int m=l+1;m<N;m++){
                ll tmp = ((A[i] * A[j]) % P )* A[k] % P * A[l] % P * A[m] % P;
                tmp %= P;
                if(tmp == Q) cnt++;
            }
        }
    }
    cout << cnt << endl;
}