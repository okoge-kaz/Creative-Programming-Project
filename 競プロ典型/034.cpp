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
    int N,K;
    cin >> N >> K;
    vector<int>a(N);
    for(int i=0;i<N;i++) cin >> a[i];

    int ans = 0;
    map<int,int>nums;
    set<int>num;
    int r = 0;
    for(int l=0;l<N;l++){
        // [l,r)
        while((int)num.size() <= K && r < N){
            if(nums[a[r]]==0) num.insert(a[r]);
            nums[a[r]]++;
            // 初めて追加のとき
            ans = max(ans,r-l);
            r++;
        }
        if((int)nums.size() <= K){
            ans = max(ans,r-l);// ここが肝
            break;
        }
        // sizeをK以下にする
        if(nums[a[l]]==1) num.erase(a[l]);
        nums[a[l]]--;
    }

    cout << ans << endl;
}