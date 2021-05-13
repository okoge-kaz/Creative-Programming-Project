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
int N,K;
int main(){
    cin >> N >> K;
    set<int>data;
    map<int,int>nums;
    vector<int>a(N);
    for(int i=0;i<N;i++) cin >> a[i];

    int r = 0;
    int ans = inf;
    for(int l=0;l<N;l++){
        while(r < N && (int)data.size() < K){
            if(a[r]<=K)  nums[a[r]]++, data.insert(a[r]);
            r++;
        }
        if((int)data.size() < K) break;
        chmin(ans,(r-l));
        if(r==l) r++;
        if(nums[a[l]]==1) data.erase(a[l]);
        nums[a[l]]--;
    }
    if(ans == inf) ans = 0;
    cout << ans << "\n";
}