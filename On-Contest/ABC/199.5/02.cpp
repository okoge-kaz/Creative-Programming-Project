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
bool is_prime(ll num){
    if(num==1) return false;
    for(ll i=2;i*i<=num;++i){
        if(num%i==0) return false;
    }
    return true;
}
int main(){
    vector<vector<int>>matrix(20,vector<int>(20));
    for(int h=0;h<20;h++){
        for(int w=0;w<20;w++){
            cin >> matrix[h][w];
        }
    }
    int cnt = 0;
    for(int h=0;h<20;h++){
        for(int w=0;w<20;w++){
            if(is_prime(matrix[h][w])) cnt++;
        }
    }
    cout << cnt << endl;
}