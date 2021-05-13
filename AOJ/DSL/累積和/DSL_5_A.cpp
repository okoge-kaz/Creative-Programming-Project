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
    int N,T;
    cin >> N >> T;
    vector<pair<int,int>>event;
    for(int i=0;i<N;i++){
        int l,r;
        cin >> l >> r;
        event.emplace_back(l,+1);
        event.emplace_back(r,-1);
    }
    sort(event.begin(),event.end());
    ll crr = 0;
    ll ans = 0;
    for(auto[time, value]:event){
        if(time > T) break;
        crr += value;
        ans = max(ans,crr); 
    }
    cout << ans << endl;
}