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
    ll N; cin >> N;
    vector<ll>A(N); for(ll &e:A) cin >> e;
    ll all = 0;
    vector<ll>sum(2*N+1);
    for(int i=0;i<N;i++){
        sum[i+1] = sum[i] + A[i];
        all += A[i];
    }
    for(int i=0;i<N;i++){
        sum[i+N+1] = sum[i+N] + A[i];
    }
    // cout << all << endl;
    for(int i=0;i<=2*N;i++){
        ll crr = sum[i];
        int idl = lower_bound(sum.begin(),sum.end(),crr+all/10)-sum.begin();
        int idr = upper_bound(sum.begin(),sum.end(),crr+all/10)-sum.begin();
        if(idr-idl==0) continue;// ぴったりの値がない
        if(idl-i>N || idl-i<=0) continue;
        if(sum[idl]-sum[i]==all/10){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}