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

ll f(ll n){
    ll res = n;
    while(n){
        res += n % 10;
        n /= 10;
    }
    return res % 100000;
}

int main(){
    // 高々10^5程度でループする
    ll N,K; cin >> N >> K;
    vector<int>nums(100001);
    nums[N]++;
    int crr = N;int stroop = 0; vector<int>vec;
    while(true){
        crr = f(crr);
        if(nums[crr]>0){
            stroop++;
            vec.push_back(crr);
            break;
        }
        nums[crr]++;
        stroop++;
        vec.push_back(crr);
    }

    vector<int>vec2;
    vector<int>nums2(100001);
    nums2[crr]++; vec2.push_back(crr);
    while(true){
        crr = f(crr);
        if(nums2[crr]>0){
            break;
        }
        nums2[crr]++;
        vec2.push_back(crr);
    }

    if( K <= stroop){
        cout << vec[K-1] << endl;
    }
    else{
        K -= stroop;
        K %= (int)vec2.size();
        cout << vec2[K] << endl;
    }
}