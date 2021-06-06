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
int main(){
    int n; cin >> n;
    int ans = 0;
    vector<pair<int,int>>event;
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        event.push_back({a,+1});
        event.push_back({b+1,-1});
    }
    int crr = 0;
    sort(event.begin(),event.end());
    for(auto[value,cnt]:event){
        crr += cnt;
        chmax(ans,crr);
    }
    cout << ans << endl;
}