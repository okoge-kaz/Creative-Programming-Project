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
    int N,K; ll P; cin >> N >> K >> P;
    vector<ll>A(N); for(int i=0;i<N;i++) cin >> A[i];
    
    int mid = N/2;
    vector<vector<ll>>vec1(N+1),vec2(N+1);
    for(int bit=0;bit<(1<<mid);bit++){
        ll cnt1 = 0; ll cnt2 = 0;
        for(int i=0;i<mid;i++){
            if(bit & (1<<i)){ cnt1 += A[i]; cnt2++; }
        }
        vec1[cnt2].push_back(cnt1);
        // vec[i] = j:= i個の品物でj円
    }
    for(int bit=0;bit<(1<<(N-mid));bit++){// このように簡潔にかける
        ll cnt1 = 0; ll cnt2 = 0;
        for(int i=0;i<(N-mid);i++){
            if(bit & (1<<i)){ cnt1 += A[mid+i]; cnt2++; }
        }
        vec2[cnt2].push_back(cnt1);
    }

    // sort
    for(int i=0;i<=N;i++){
        // 二分探索のためにsort
        sort(vec1[i].begin(),vec1[i].end());
        sort(vec2[i].begin(),vec2[i].end());
    }
    
    ll ans = 0;
    for(int i=0;i<=K;i++){
        for(int j=0;j<(int)vec1[i].size();j++){
            ll pos = upper_bound(vec2[K-i].begin(),vec2[K-i].end(),P-vec1[i][j]) - vec2[K-i].begin();
            ans += pos;
        }
    }
    cout << ans << endl;
}