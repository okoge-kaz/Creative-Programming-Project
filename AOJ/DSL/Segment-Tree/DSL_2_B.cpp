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
// range sum query

// ここのoperationは適時変える
ll op(ll x, ll y){
    return x+y;
}

class SegmentTree {
    private:
        ll SEG_LEN;
        vector<ll>node;
    public:
        SegmentTree(ll N){
            SEG_LEN = 1LL;
            while(SEG_LEN < N) SEG_LEN *= 2;// 十分な大きさ
            node.resize(2*SEG_LEN, 0LL);// 初期値をここの第二引数に書く
            // 例 Range Sum Queryなら 0 , Range Minimum QueryならINF 
        }

        void update(ll index, ll value){
            // １点更新
            index += (SEG_LEN);
            node[index] += value;
            while(index > 0){//終了条件
                // node[0]はあるけど使っていない
                index /= 2;
                node[index] = op(node[2*index] , node[2*index+1LL]);// opを変えれば、ここはイジらなくてよい
            }
        }

        ll query(int l, int r){
            l += SEG_LEN;
            r += SEG_LEN;
            ll ans = 0;// ここも問題によって変更
            // Range Sum Queryなら ans = 0, Range Minimum Queryなら ans = INF

            while(l < r){
                // [l,r)の区間について考える

                if(l % 2 == 1){
                    // 奇数の時は上に登れない
                    ans += node[l];// ここも変更
                    l++;
                }
                l /= 2;

                if(r % 2 == 1){
                    ans += node[r-1];// ここも変更
                    r--;
                }
                r /= 2;
            }
            return ans;
        }
};

int main(){
    ll N,Q;
    cin >> N >> Q;
    SegmentTree sg(N);
    for(int q=0;q<Q;q++){
        ll com, l, r;
        cin >> com >> l >> r;
        if(com == 0){
            sg.update(l,r);
        }
        else{
            cout << sg.query(l,r+1) << "\n";
        }
    }
}