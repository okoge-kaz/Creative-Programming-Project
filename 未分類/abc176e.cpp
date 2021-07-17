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
    // 無理矢理解くことも重要
    int H,W,M; cin >> H >> W >> M;
    vector<ll>h(M),w(M);
    for(int i=0;i<M;i++) cin >> h[i] >> w[i];
    set<pair<ll,ll>>st; for(int i=0;i<M;i++) st.insert(pair(h[i],w[i]));
    ll ans = 0;
    map<ll,ll>hdata,wdata; for(int i=0;i<M;i++){ hdata[h[i]]++; wdata[w[i]]++; }
    vector<pair<ll,ll>>cnt_h,cnt_w;
    for(auto[value,cnt]:hdata)cnt_h.push_back(pair(cnt,value));
    for(auto[value,cnt]:wdata)cnt_w.push_back(pair(cnt,value));
    sort(cnt_h.begin(),cnt_h.end(),greater<pair<int,int>>());
    sort(cnt_w.begin(),cnt_w.end(),greater<pair<int,int>>());

    vector<ll>max_h,max_w;
    for(auto[cnt,value]:cnt_h) if(cnt==cnt_h[0].first) max_h.push_back(value);
    for(auto[cnt,value]:cnt_w) if(cnt==cnt_w[0].first) max_w.push_back(value);

    chmax(ans,cnt_h[0].first+cnt_w[0].first-1);
    for(ll eh:max_h) for(ll ew:max_w){
        if(st.find({eh,ew})!=st.end()) chmax(ans,cnt_h[0].first+cnt_w[0].first-1);
        else{ chmax(ans,cnt_h[0].first+cnt_w[0].first); cout << ans << endl; return 0; }
    }
    // 枝刈りでギリギリ解けるタイプの問題もある

    cout << ans << endl;
}