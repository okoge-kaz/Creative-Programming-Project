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

template <typename T>
vector<T> Compress(vector<T> &C1, vector<T> &C2){
    vector<T> vals;
    int N = (int)C1.size();
    for(int i=0;i<N;i++){
        for(T d=0;d<1;d++){
            // 1つ隣も確保
            T tc1 = C1[i] + d;
            T tc2 = C2[i] + d;
            vals.push_back(tc1);
            vals.push_back(tc2);
        }
    }
    sort(vals.begin(),vals.end());
    // 重複を削除
    vals.erase(unique(vals.begin(),vals.end()),vals.end());
    for(int i=0;i<N;i++){
        C1[i] = lower_bound(vals.begin(),vals.end(),C1[i]) - vals.begin();
        C2[i] = lower_bound(vals.begin(),vals.end(),C2[i]) - vals.begin();
    }
    return vals;
}

int main(){
    // 10^9 * 10^9 は流石にメモリ上にのらない
    // 座標圧縮を考える
    ll N;
    cin >> N;
    vector<ll>X1(N),Y1(N),X2(N),Y2(N);
    for(int i=0;i<N;i++){
        cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
    }
    // compression
    vector<ll>X = Compress(X1,X2);
    vector<ll>Y = Compress(Y1,Y2);
    // X1, X2, Y1, Y2が座標圧縮した結果で、受け取ったX,Yは座標圧縮する前の座標群
    // imos法
    int h = (int)Y.size(), w = (int)X.size();
    // この大きさは上のように圧縮した個数が入っているので
    vector<vector<int>>G(h,vector<int>(w));
    for(int i=0;i<N;i++){
        G[Y1[i]][X1[i]]++;
        G[Y1[i]][X2[i]]--;
        G[Y2[i]][X1[i]]--;
        G[Y2[i]][X2[i]]++;
    }
    for(int y=0;y<h;y++){
        for(int x=0;x<w-1;x++){
            G[y][x+1] += G[y][x];
        }
    }
    for(int x=0;x<w;x++){
        for(int y=0;y<h-1;y++){
            G[y+1][x] += G[y][x];
        }
    }

    ll ans = 0;
    for(int y=0;y<h-1;y++){
        for(int x=0;x<w-1;x++){
            // -1しているのは、一番外側は予備の空白だから
            if(G[y][x] > 0){
                // 1枚以上のものがあったら
                ans += (X[x+1] - X[x]) * (Y[y+1] - Y[y]);
            }

        }
    }
    cout << ans << "\n";
}