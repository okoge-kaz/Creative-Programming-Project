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
    // input
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    // sortしても結果が変わらないようにしたい。
    vector<pair<int,int>>pa(n);
    for(int i=0;i<n;i++) pa[i].first = a[i], pa[i].second = i;
    sort(pa.begin(),pa.end());
    sort(a.begin(),a.end());
    // 全ての場合でcombinationを計算することは不可能
    // k <= n/2 のときは comb(n, k) > comb(n, k-1)
    int place = lower_bound(a.begin(),a.end(),a[n-1]/2.0) - a.begin();
    ll half_1 = a[place];
    ll half_2;
    int place_2 = place-1;
    if(place == 0) half_2 = a[0], place_2 = 0;
    else half_2 = a[place_2];
    if(abs(half_1 - a[n-1]/2.0) < abs(half_2 - a[n-1]/2.0)){
        cout << pa[n-1].first << " " << pa[place].first << endl; 
    }
    else cout << pa[n-1].first << " " << pa[place_2].first << endl;
    // 結果としては、pairを使う必要は全くなかった
}