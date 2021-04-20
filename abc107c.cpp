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
    // input
    int N,K;
    cin >> N >> K;
    vector<int>x(N);
    for(int i=0;i<N;i++) cin >> x[i];
    
    // 数直線は - 10^8 <= x <= 10^8なので、どうするか
    ll min_time = INF;
    vector<int>px, nx;// positive x, nagative x 正の座標と、負の座標に分ける
    for(int i=0;i<N;i++){
        if(x[i] < 0) nx.push_back(-x[i]);
        else px.push_back(x[i]);
    }
    reverse(nx.begin(),nx.end());// ０から違い順の距離になっている
    for(int i=0;i<=K;i++){
        // pxからi個とる
        ll tmp1 = 0, tmp2 = 0;
        if(nx.size() < (K - i))continue;
        if(px.size() < i) continue;
        // tmp1
        if(K-1-i >= 0){
            tmp1 += 2LL * (nx[K-1-i]);// K - i個目まで行って戻る
        }
        if(i > 0){
            tmp1 += 1LL * px[i-1];
        }
        // tmp2
        if(K -1 -i >= 0){
            tmp2 += (nx[K-1-i]);
        }
        if(i > 0) tmp2 += 2LL*(px[i-1]);
        min_time = min(min_time, tmp1);
        min_time = min(min_time, tmp2);
    }
    cout << min_time << endl;
}