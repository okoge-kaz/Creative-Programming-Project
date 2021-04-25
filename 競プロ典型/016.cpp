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
    ll N, A, B, C;
    cin >> N >> A >> B >> C;

    ll cnt = INF;
    vector<ll>coin;
    coin.push_back(A),coin.push_back(B),coin.push_back(C);
    sort(coin.begin(),coin.end());
    A = coin[0], B = coin[1], C = coin[2];
    
    for(int i=0;i<10000;i++){
        for(int j=0;j<10000;j++){
            if((N - A*i - B*j)%C==0){
                cnt = min(cnt, i+j+((N - A*i - B*j)/C));
            }
        }
    }
    cout << cnt << endl; 
}