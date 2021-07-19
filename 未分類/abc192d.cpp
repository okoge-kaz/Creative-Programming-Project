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
ll m; string x;
bool check(ll d){
    lll tmp = 0;
    // この書き方だと桁に0がある場合はバグのもと
    lll digit = 1;
    for(int i=0;i<(int)x.size();i++){
        digit *= d;
        tmp += digit*(x[i]-'0');// '0'が0になっていた注意!!
        if(tmp > m) return false;
    }
    return tmp <= m;
}
int main(){
    cin >> x; int d = 0; reverse(x.begin(),x.end());
    for(char c:x) chmax(d,c-'0');
    int l = d++;
    cin >> m;
    // corner case
    if((int)x.size()==1){
        if(m >= x[0]-'0'){
            cout << 1 << endl;
            return 0;
        }
        else {cout << 0 << endl; return 0; }
    }
    // binary search
    ll ok = l; ll ng = INF;
    while(abs(ok-ng)>1){
        ll mid = (ok+ng)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok-l << endl;
}