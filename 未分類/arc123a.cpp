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
int main(){
    ll a,b,c; cin >> a >> b >> c;
    ll d1 = (b - a); ll d2 = (c -b);
    ll ans = 0;
    if(d1!=d2){
        if(d1 >= 0 && d2 >= 0){
            if(d2 > d1 && (d2-d1)%2==1) ans += ceil((d2-d1)/2.0) + 1;
            else if(d2 > d1 && (d2-d1)%2==0) ans += (d2-d1)/2;
            else{
                // d1 > d2
                ans += (d1-d2);
            }
        }
        else if(d1 < 0 && d2 >= 0){
            if((d2-d1)%2==0) ans += (d2-d1)/2;
            else{
                ans += ceil((d2-d1)/2.0)+1;
            }
        }
        else if(d1 >= 0 && d2 < 0){
            ans += (d1-d2);
        }
        else{
            if(d1 < d2 && abs(d1-d2)%2==0){
                ans += abs(d1-d2)/2;
            }
            else if(d1 < d2 && abs(d1-d2)%2==1){
                ans += ceil(abs(d1-d2)/2.0) + 1;
            }
            else{
                // d2 < d1
                ans += abs(d2-d1);
            }
        }
    }

    cout << ans << endl;
}