#include <bits/stdc++.h>
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
using lll = __int128_t;
string N; int n=0;
vector dp(10,vector(2,vector<ll>(10,-1LL)));
ll rec(int d=0,bool smaller=false,int remain=0){
    if(d >= n) return 0;
    ll &res = dp[d][(int)smaller][remain];
    if(res >= 0) return res;

    res = 0;
    if(smaller){
        for(int i=0;i<10;i++){
            if(i!=1)res += rec(d+1,true,i);
            else res += rec(d+1,true,i)+1;
        }
    }
    else{
        int digit = N[d]-'0';
        for(int i=0;i<digit;i++){
            if(i==1) res += rec(d+1,true,i)+1;
            else res += rec(d+1,true,i);
        }
        if(digit==1)res += rec(d+1,false,digit)+1;
        else res += rec(d+1,false,digit);
    }
    return res;
}
int main(){
    cin >> N;
    n = (int)N.size();
    cout << rec() << endl;
}