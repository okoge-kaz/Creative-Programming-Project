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
ll K;
string S,T;
bool isOK(int ca,int cb, map<ll,ll>nums){
    nums[ca]++;
    nums[cb]++;
    for(auto [value,cnt]:nums){
        if(cnt > K) return false;
    }
    return true;
}
int main(){
    cout << std::fixed << std::setprecision(15);
    cin >> K;
    cin >> S >> T;
    map<ll,ll>A,B;
    map<ll,ll>nums;
    for(int i=0;i<4;i++){
        A[S[i]-'0']++;
        B[T[i]-'0']++;
        nums[S[i]-'0']++;
        nums[T[i]-'0']++;
    }
    ld pro = 0;
    for(int ca=1;ca<=9;ca++){
        for(int cb=1;cb<=9;cb++){
            ll tmpa = 0, tmpb = 0;
            if(!isOK(ca,cb,nums)) continue;
            ll a = (K-nums[ca]);
            nums[ca]++;
            ll b = (K-nums[cb]);
            nums[ca]--;
            A[ca]++, B[cb]++;
            for(ll i=1;i<=9;i++){
                tmpa += i * (ll)pow(10,A[i]);
                tmpb += i * (ll)pow(10,B[i]);
            }
            A[ca]--,B[cb]--;
            if(tmpa > tmpb) pro += (ld)(a*b)/((ld)(9*K - 8)*(9*K-9));
        }
    }
    cout << pro << endl;
}