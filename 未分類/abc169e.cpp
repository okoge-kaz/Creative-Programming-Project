#include <bits/stdc++.h>
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
// 解説: https://blog.hamayanhamayan.com/entry/2020/06/01/210806
// 公式解説にもある通り https://img.atcoder.jp/abc169/editorial.pdf
// とりうる中央値が連続的に配置されていることを見抜く必要がある

int main(){
    int n; cin >> n;
    vector<ll>a(n),b(n);
    for(int i=0;i<n;i++) cin >> a[i] >> b[i];

    sort(a.begin(),a.end()); sort(b.begin(),b.end());
    if(n%2==0){
        // 0.5 1 1.5 ... となるので
        // a, bを調整すると~.5も中央値たりえるので
        ll l = (a[n/2]+a[n/2-1]);
        ll r = (b[n/2]+b[n/2-1]);
        cout << (r-l+1) << endl;
    }
    else{
        ll l = (a[n/2]); ll r = b[n/2];
        cout << (r-l+1) << endl;
    }
}