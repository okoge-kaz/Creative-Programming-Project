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
using lll = __int128_t;
int main(){
    ll N,M; cin >> N >> M;
    vector<ll>A(N),B(N);
    for(int i=0;i<N;i++) cin >> A[i] >> B[i];

    vector<pair<ll,ll>>BA(N);
    for(int i=0;i<N;i++) BA[i] = pair(B[i],A[i]);
    sort(BA.begin(),BA.end(),greater<pair<ll,ll>>());
    // greedyですると間違う 
    // dpで解こうとしても計算量がO(NM)かかってしまう
    // 貪欲法の実装例
    // ll ans = 0; ll crr = M;
    // for(int i=0;i<N;i++){
    //     if(BA[i].second <= crr){
    //         ans += BA[i].first;
    //         crr--;
    //     }
    // }
    // cout << ans << endl;

    // 逆順にみるとうまくいく
    vector<pair<ll,ll>>AB(N);
    for(int i=0;i<N;i++) AB[i] = pair(A[i],B[i]);
    sort(AB.begin(),AB.end());
    priority_queue<ll>que;
    ll ans = 0;
    int id = 0;
    for(int i=0;i<=M;i++){
        while(AB[id].first<=i){
            if(id>=N) break;// これ書かないと無限ループになる
            que.push(AB[id].second);
            id++;
        }
        if(que.empty()) continue;
        ans += que.top(); que.pop();
    }
    cout << ans << endl;
}