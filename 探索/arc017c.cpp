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
    ll X; cin >> X;
    vector<ll>w(N); for(int i=0;i<N;i++) cin >> w[i];

    int mid = N/2;
    ll ans = 0;
    vector<ll>vec1,vec2;
    for(int bit=0;bit<(1<<mid);bit++){
        ll acc = 0;
        for(int i=0;i<mid;i++){
            if(bit & (1<<i)){ acc += w[i]; }
        }
        vec1.push_back(acc);
    }
    for(int bit=0;bit<(1<<(N-mid));bit++){
        ll acc = 0;
        for(int i=0;i<(N-mid);i++){
            if(bit & (1<<(i))){ acc += w[mid+i]; }
        }
        vec2.push_back(acc);
    }
    sort(vec1.begin(),vec1.end());
    sort(vec2.begin(),vec2.end());
    for(ll e:vec1){
        ll cnt = upper_bound(vec2.begin(),vec2.end(),X-e) - lower_bound(vec2.begin(),vec2.end(),X-e);
        ans += cnt;
    }
    cout << ans << endl;
}