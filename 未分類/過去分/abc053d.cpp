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
    int N; cin >> N;
    vector<int>A(N); for(int i=0;i<N;i++) cin >> A[i];
    int ans = N;
    int l=1; int r=100000;
    vector<int>nums(100001);
    for(int i=0;i<N;i++) nums[A[i]]++;

    while(true){
        while(nums[l]<=1) l++;
        while(nums[r]<=1) r--;
        if(l>=r){
            if(l==r && nums[l] > 1){
                while(nums[l]>=3){
                    ans -= 2;
                    nums[l]-=2;
                }
                if(nums[l]==2){
                    ans -= 2;
                }
            }
            break;
        }
        ans -= 2;
        nums[l]--; nums[r]--;
    }
    cout << ans << endl;
}