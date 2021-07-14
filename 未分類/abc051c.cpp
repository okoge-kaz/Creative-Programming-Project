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
    int sx,sy,tx,ty; cin >> sx >> sy >> tx >> ty;
    int dx = (tx - sx); int dy = (ty - sy);
    string ans;
    // 1回目の進行
    for(int i=0;i<abs(dx);i++){
        if(dx < 0) ans.push_back('L');
        else ans.push_back('R');
    }
    for(int i=0;i<abs(dy);i++){
        if(dy < 0) ans.push_back('D');
        else ans.push_back('U');
    }
    // 1回目の後退
    for(int i=0;i<abs(dx);i++){
        if(dx < 0) ans.push_back('R');
        else ans.push_back('L');
    }
    for(int i=0;i<abs(dy);i++){
        if(dy < 0) ans.push_back('U');
        else ans.push_back('D');
    }
    // 2回目の進行
    if(dy >= 0) ans.push_back('D');

    else ans.push_back('U');
    for(int i=0;i<abs(dx)+1;i++){
        if(dx < 0) ans.push_back('L');
        else ans.push_back('R');
    }
    for(int i=0;i<abs(dy)+1;i++){
        if(dy < 0) ans.push_back('D');
        else ans.push_back('U');
    }

    if(dx >= 0) ans.push_back('L');
    else ans.push_back('R');
    // 2回目の後退
    if(dy >= 0) ans.push_back('U');
    else ans.push_back('D');

    
    for(int i=0;i<abs(dx)+1;i++){
        if(dx < 0) ans.push_back('R');
        else ans.push_back('L');
    }
    for(int i=0;i<abs(dy)+1;i++){
        if(dy < 0) ans.push_back('U');
        else ans.push_back('D');
    }

    if(dx >= 0) ans.push_back('R');
    else ans.push_back('L');
    //
    cout << ans << endl;
}