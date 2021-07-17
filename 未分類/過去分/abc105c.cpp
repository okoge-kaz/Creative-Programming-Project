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
    // 2の補数という概念を忘れていたので、ちゃんと思い出すこと
    // でも今回は違う
    int N; cin >> N;
    string ans;
    // なぜこれでできるかいまいち分かっていない
    while(N){
        int r = N % 2;
        if(r<0) r += 2;

        N = (N-r) / (-2);
        ans += (char)('0'+r);
    }
    reverse(ans.begin(),ans.end());
    if(ans=="") ans = "0";//この例外処理は忘れずに かなり盲点
    cout << ans << endl;
}