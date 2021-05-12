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
// 素因数分解する関数
vector<pair<ll,ll>> prime_factorize(ll N){
    vector<pair<ll,ll>>res;
    for(ll i=2;i*i <= N;i++){
        if(N % i != 0) continue;
        ll num = 0;
        while(N % i == 0){
            num++;
            N /= i;// これで素数だけが取れる
        }
        res.push_back({i,num});
    }
    if(N != 1) res.push_back({N,1});//素数の時
    return res;
}
ld dp[101][64][64][64];
int main(){
    cout << std::fixed << std::setprecision(15) ;

    ll N, D;
    cin >> N >> D;
    auto primes = prime_factorize(D);
    int a = 0, b = 0, c = 0;
    for(auto[value,cnt]:primes){
        if(value == 2 || value == 3 || value == 5){
            if(value==2) a = cnt;
            if(value==3) b = cnt;
            if(value==5) c = cnt;
            continue;
        }
        cout << 0 << "\n";
        return 0;
    }

    dp[0][0][0][0] = 1;
    for(int i=0;i<N;i++){
        for(int x=0;x<64;x++){
            for(int y=0;y<64;y++){
                for(int z=0;z<64;z++){
                    // 1
                    dp[i+1][min(x,a)][min(y,b)][min(z,c)] += dp[i][x][y][z] * (1.0 / 6);
                    // 2 
                    dp[i+1][min(x+1,a)][min(y,b)][min(z,c)] += dp[i][x][y][z] * (1.0 / 6);
                    // 3
                    dp[i+1][min(x,a)][min(y+1,b)][min(z,c)] += dp[i][x][y][z] * (1.0 / 6);
                    // 4
                    dp[i+1][min(x+2,a)][min(y,b)][min(z,c)] += dp[i][x][y][z] * (1.0 / 6);
                    // 5
                    dp[i+1][min(x,a)][min(y,b)][min(z+1,c)] += dp[i][x][y][z] * (1.0 / 6);
                    // 6
                    dp[i+1][min(a,x+1)][min(b,y+1)][min(c,z)] += dp[i][x][y][z] * (1.0 / 6);
                }
            }
        }
    }
    cout << dp[N][a][b][c] << "\n";
}