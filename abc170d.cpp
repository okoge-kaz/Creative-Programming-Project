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
    const ll MAX = 1100000LL;
    ll N;
    cin >> N;
    vector<ll>A(N);
    for(int i=0;i<N;i++) cin >> A[i];
    // 愚直に考えるとO(N^2)
    vector<ll>nums(MAX);
    for(int i=0;i<N;i++){
        nums[A[i]]++;
    }
    for(int i=1;i<MAX;i++){
        if(nums[i]==0) continue;
        if(nums[i] > 1) nums[i] = 0;//同じ数があるなら割り切れてしまう
        for(ll n=i*2;n<MAX;n+=i){
            //倍数を消去する、ここの計算量は一見するとO(N)だが、実はO(log N)
            nums[n] = 0;
        }
    }
    ll ans = 0;
    for(int i=1;i<MAX;i++) ans += nums[i];
    // 1が残っているところは、エラトステネスの篩のようにしたので、なにでも割り切れないもの
    cout << ans << endl;
}