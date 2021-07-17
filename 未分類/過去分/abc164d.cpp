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
    // 2019 = 673 * 3
    // 解説: https://blog.hamayanhamayan.com/entry/2020/04/26/232032
    string s; cin >> s; int N = (int)s.size();
    reverse(s.begin(),s.end());
    ll ans = 0; vector<int>cnt(2020);
    cnt[0] = 1;
    int d = 1;// digit
    int crr = 0;
    for(int i=0;i<N;i++){
        crr = (crr + (s[i]-'0') * d) % 2019;
        ans += cnt[crr];// 自分と同じなもの同士は上手くなるから
        d = (d*10)%2019;
        cnt[crr]++;
    }
    cout << ans << endl;
}