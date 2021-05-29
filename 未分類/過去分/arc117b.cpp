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
    int N;
    cin >> N;
    vector<ll>A(N);
    for(int i=0;i<N;i++) cin >> A[i];
    
    map<ll,ll>height;
    for(int i=0;i<N;i++) height[A[i]]++;
    // 同じ高さのものは１つにまとめて考えてよい
    vector<ll>h;
    for(auto [high,cnt]:height) h.push_back(high);
    // 異なる高さのみの配列
    sort(h.begin(),h.end(), greater<ll>());// 降順
    // sortしても求める総数に変化は生じない
    ll ans = 1;
    // 高さが同じものがいくつあるかを考える
    for(int i=0;i<h.size();i++){
        if(i==h.size()-1){
            ans *= (h[i] - 0 + 1);
            ans %= MOD;
            continue;
            // この処理をしないためには、番兵として0を配列に入れる必要がある
        }
        ans *= (h[i] - h[i+1] + 1);// +1は、0階同じな場合を考えている。
        ans %= MOD;
    }
    cout << ans << endl;
}