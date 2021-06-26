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
    int N; cin >> N;
    vector<int>A(N); for(int &e:A) cin >> e;
    // LIS Longest Inceasing Subsequence
    vector<int>dp1(N,inf); vector<int>P(N),Q(N);
    for(int i=0;i<N;i++){
        int id = lower_bound(dp1.begin(),dp1.end(),A[i]) - dp1.begin();
        dp1[id] = A[i];
        P[i] = id;
    }
    vector<int>dp2(N,inf);
    for(int i=N-1;i>=0;i--){
        int id = lower_bound(dp2.begin(),dp2.end(),A[i]) - dp2.begin();
        dp2[id] = A[i];
        Q[i] = id;
    }
    int ans = 0;
    for(int i=0;i<N;i++) chmax(ans,(P[i]+1)+(Q[i]+1)-1);
    cout << ans << endl;
}