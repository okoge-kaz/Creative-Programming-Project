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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    int N;
    cin >> N;
    // 桁操作関連の技術がかなり弱いので精進あるのみ
    ll ans = 0;
    vector<vector<ll>>num(10,vector<ll>(10));
    // 本問においては、最高位の桁の数と、最下位の桁の数以外関係がないことを見抜くことが重要
    for(int i=1;i<=N;i++){
        string n = to_string(i);
        int t = n.back()-'0';//末尾をback()でとれることを知らなかった
        int b = n[0] - '0';
        if(t==0 || b==0) continue;
        num[t][b]++;
    }
    for(int i=1;i<10;i++) for(int j=1;j<10;j++) ans += num[i][j] * num[j][i];
    cout << ans << endl;
}