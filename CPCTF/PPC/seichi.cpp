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
ll H,W;
vector<vector<ll>>A;
int main(){
    cin >> H >> W;
    A.resize(H,vector<ll>(W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> A[i][j];
        }
    }

    vector<ll>data;
    for(int h=0;h<H;h++){
        for(int w=0;w<W;w++){
            data.push_back(A[h][w]);
        }
    }
    sort(data.begin(),data.end());
    if((H*W)%2==0 ){
        ll mid1;
        ll mid2 = data[H*W/2];
        if(H*W/2 -1 >= 0){
            ll mid1 = data[H*W/2 -1];
        }
        else{
            mid1 = mid2;
        }
        ll tmp1 =0, tmp2 = 0;
        for(int h=0;h<H;h++){
            for(int w=0;w<W;w++){
                tmp1 += abs(A[h][w] - mid1);
                tmp2 += abs(A[h][w] - mid2);
            }
        }
        cout << min(tmp1,tmp2) << endl;
    }
    else{
        ll mid = data[H*W/2];
        ll ans = 0;
        for(int h=0;h<H;h++){
            for(int w=0;w<W;w++){
                ans += abs(A[h][w] - mid);
            }
        }
        cout << ans << endl;
    }
}