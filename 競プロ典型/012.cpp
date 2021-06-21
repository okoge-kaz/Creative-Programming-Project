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
int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

class UnionFind {
    private:
        vector<ll>par, siz, depth;// 親ノード、要素数、深さ
    public:
        UnionFind(ll N) : par(N,-1LL), siz(N, 1LL), depth(N, 1LL) {}
        ll root(ll x){// 根を求める
            if(par[x]==-1) return x;
            else return par[x] = root(par[x]);// 経路圧縮
        }
        bool issmae(ll x,ll y){
            return root(x)==root(y);
        }
        bool unite(ll x, ll y){
            x = root(x), y = root(y);// x,yの値まで移動する
            if(x==y) return false;
            if(depth[x]<depth[y]) swap(x,y);// 常にxの方が深い
            if(depth[x]==depth[y]) depth[x]++;
            par[y] = x; siz[x] += siz[y];
            return true;
        }
        ll size(ll x){
            return siz[root(x)];// xを含むグループのサイズ
        }
        ll deep(ll x){
            return depth[root(x)];
        }
};

int main(){
    // 連結判定はUnionFind
    // 問われていることが連結かどうかだけなのでUnionFindがよいと思いつくべし
    int H,W; cin >> H >> W;
    int Q; cin >> Q;
    UnionFind uf(H*W);
    vector<vector<bool>>red(H,vector<bool>(W,false));
    // query
    for(int i=0;i<Q;i++){
        int t; cin >> t;
        if(t==1){
            int r,c; cin >> r >> c;
            r--,c--;
            red[r][c] = true;
            for(int i=0;i<4;i++){
                int ny = r + dy[i]; int nx = c + dx[i];
                if(ny<0 || nx<0 || nx >=W || ny >= H) continue;
                if(!red[ny][nx]) continue;//赤ではない
                // 2次座標におけるUnionFindのときは以下のようにハッシュ化する
                int hash1 = r*W+c; int hash2 = ny*W+nx;
                uf.unite(hash1,hash2);
            }
        }
        else{
            int ra,ca,rb,cb; cin >> ra >> ca >> rb >> cb;
            ra--,ca--,rb--,cb--;
            if(red[ra][ca]==false||red[rb][cb]==false){
                cout << "No" << endl;
            }
            else{
                int hash1 = ra*W+ca; int hash2 = rb*W+cb;
                if(uf.issmae(hash1,hash2)) cout << "Yes" << endl;
                else cout << "No" << endl;
            }

        }
    }
}