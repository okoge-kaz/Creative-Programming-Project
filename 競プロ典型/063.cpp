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
    int H,W; cin >> H >> W;
    vector<vector<int>>P(H,vector<int>(W));
    for(int i=0;i<H;i++) for(int j=0;j<W;j++){
        cin >> P[i][j];
    }

    ll ans = 0;
    for(int bit=0;bit<(1<<H);bit++){
        vector<int>hs;
        for(int i=0;i<H;i++){
            if(bit & (1<<i)) hs.push_back(i);
        }
        //
        if((int)hs.size()<=0) continue;
        ll tmp = 0; map<int,int>data;
        for(int w=0;w<W;w++){
            bool frg = true;
            int color = P[hs[0]][w];
            for(int e:hs) if(P[e][w]!=color) frg = false;
            if(frg) data[color]++;
        }
        int cnt = 0;
        for(auto[value,cn]:data) chmax(cnt,cn);
        tmp = cnt * (int)hs.size();
        chmax(ans,tmp);
    }
    cout << ans << endl;
}