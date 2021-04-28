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
    int N;
    cin >> N;
    vector<ll>A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }

    int minus = 0;
    for(int i=0;i<N;i++) if(A[i] < 0) minus++;
    
    ll ans = 0;
    if(minus % 2==0){
        for(int i=0;i<N;i++){
            ans += abs(A[i]);
        }
    }
    else{
        ll minimum = INF;
        for(int i=0;i<N;i++){
            ans += abs(A[i]);
            minimum = min(minimum,abs(A[i]));
        }
        ans -= 2*minimum;
    }
    cout << ans << endl;
}