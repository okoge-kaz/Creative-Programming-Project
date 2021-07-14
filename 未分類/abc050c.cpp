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
using mint = modint1000000007;
using lll = __int128_t;
int main(){
    int N; cin >> N; vector<int>A(N); for(int &e:A) cin >> e;
    mint ans = 1; vector<int>nums(N);
    for(int i=0;i<N;i++){
        if((N-1-A[i])%2!=0){
            cout << 0 << endl;
            return 0;
        }
        int l = (N-1-A[i])/2; int r = (N-1+A[i])/2;
        nums[l]++; nums[r]++;
    }
    for(int i=0;i<N;i++){
        if(nums[i]%2!=0){
            cout << 0 << endl;
            return 0;
        }
    }
    if(N%2==0) for(int i=0;i<N/2;i++) ans *= nums[i];
    else{ 
        for(int i=0;i<N/2;i++)ans *= nums[i];
        ans *= nums[N/2]/2;
    }
    cout << ans.val() << endl;
}