#include <bits/stdc++.h>
#include <atcoder/all>
#define _GLIBCXX_DEBUG
using namespace std;
using namespace atcoder;
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
    ll N;
    cin >> N;
    string n = to_string(N);
    int k = (int)n.size();

    int ans = inf;
    for(int bit=0;bit<(1<<k);bit++){
        int digit_sum = 0;
        int cnt = 0;
        for(int i=0;i<k;i++){
            if(bit & (1<<i)){
                cnt++;
                digit_sum += (int)(n[i]-'0');
            }
        }
        if(cnt == 0) continue;// 一つも選んでいないのはダメ
        if(digit_sum % 3 == 0){
            ans = min(ans,(k-cnt));
        }
    }
    if(ans == inf) cout << -1 << endl;
    else cout << ans << endl;
}