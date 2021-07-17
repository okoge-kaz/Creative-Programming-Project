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
// reference is snuke's submission
int main(){
    // 逆元についてちゃんと分かっていない
    // 桁上がりの10とmodの値が互いに素である限り以下のように解くことができる
    string s; cin >> s;
    int n = s.size(); reverse(s.begin(),s.end());
    int x = 1; int tot = 0;// total
    vector<int>cnt(2019);// あまりを保存
    ll ans = 0;
    for(int i=0;i<n;i++){
        cnt[tot]++;
        tot += (s[i]-'0')*x;
        tot %= 2019;
        ans += cnt[tot];
        x = x*10 % 2019;
    }
    cout << ans << endl;
}