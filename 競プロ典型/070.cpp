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
    // マンハッタン距離だからといって数式を展開すればよいというわけではない
    int N; cin >> N;
    vector<ll>X(N), Y(N);
    for(int i=0;i<N;i++){
        cin >> X[i] >> Y[i];
    }
    sort(X.begin(),X.end()); sort(Y.begin(),Y.end());
    ll ans = 0;
    ll tmp1 = 0, tmp2 = 0; ll x = INF; ll y = INF;
    for(int i=0;i<N;i++){
        tmp1 += abs(X[i]-X[N/2]);
        tmp2 += abs(X[i]-X[N/2 + 1]);
    }
    x = min(tmp1,tmp2);
    tmp1 = 0, tmp2 = 0;
    for(int i=0;i<N;i++){
        tmp1 += abs(Y[i]-Y[N/2]);
        tmp2 += abs(Y[i]-Y[N/2+1]);
    }
    y = min(tmp1,tmp2);
    ans = x + y;
    cout << ans << endl;
}