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
unsigned long long Pow(unsigned long long c, unsigned long long b){
    unsigned long long res = 1;
    for(unsigned long long i=0;i<b;i++){
        res *= c;
    }
    return res;
}
int main(){
    unsigned long long a, b, c;
    cin >> a >> b >> c;
    if(a < Pow(c,b)) cout << "Yes" << endl;
    else cout << "No" << endl;
}