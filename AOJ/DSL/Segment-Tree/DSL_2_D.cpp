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
// Range Update Query

// ここのoperationは適時変える
ll op(ll x, ll y){
    return x+y;
}

class SegmentTree {
    private:
        ll SEG_LEN;
        vector<pair<ll,ll>>node;// RUQのときにはこのようにもつ
        ll t = 0;
    public:
        SegmentTree(ll N){
            SEG_LEN = 1LL;
            while(SEG_LEN < N) SEG_LEN *= 2;// 十分な大きさ
            node.resize(2*SEG_LEN, {0LL, (1LL << 31)-1});// 初期値をここの第二引数に書く
            // 例 Range Sum Queryなら 0 , Range Minimum QueryならINF 
        }

        ll query(ll index){
            // 1点取得
            index += (SEG_LEN);
            pair<ll,ll> res = node[index];//返値
            while(index > 0){//終了条件
                // node[0]はあるけど使っていない
                index /= 2;
                chmax(res,node[index]);// １点なので上に登っていくだけで良い
                // pair<ll,ll> = { t, value}としているので、自動的に t が大きいもののデータに更新される
            }
            return res.second;
        }

        void update(int l, int r, ll value){
            // 区間更新
            l += SEG_LEN;
            r += SEG_LEN;
            t++;//何回目の更新なのかを表す

            while(l < r){
                // [l,r)の区間について考える

                if(l % 2 == 1){
                    // 奇数の時は上に登れない
                    node[l] = {t,value};// ここも変更
                    l++;
                }
                l /= 2;

                if(r % 2 == 1){
                    node[r-1] = {t,value};// ここも変更
                    r--;
                }
                r /= 2;
            }
        }
};

int main(){
    ll N,Q;
    cin >> N >> Q;
    SegmentTree sg(N);
    // segmentreeは1-indexにしているのでとくに--する必要はない
    for(int q=0;q<Q;q++){
        ll com;
        cin >> com ;
        if(com == 0){
            ll l, r, x;
            cin >> l >> r >> x;
            sg.update(l,r+1,x);
        }
        else{
            ll index;
            cin >> index;
            cout << sg.query(index) << endl;
        }
    }
}