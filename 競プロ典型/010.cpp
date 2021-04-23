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
    vector<ll>C(N), P(N);
    for(int i=0;i<N;i++){
        cin >> C[i] >> P[i];
    }
    vector<ll>sum1(N+1),sum2(N+1);
    for(int i=0;i<N;i++){
        if(C[i]==1){
            sum1[i+1] = sum1[i] + P[i];
            sum2[i+1] = sum2[i];
        }
        else sum2[i+1] = sum2[i] + P[i], sum1[i+1] = sum1[i];
    }
    int Q;
    cin >> Q;
    for(int i=0;i<Q;i++){
        int L, R;
        cin >> L >> R;
        cout << sum1[R] - sum1[L-1] << " " << sum2[R] - sum2[L-1] << endl;
    }
}