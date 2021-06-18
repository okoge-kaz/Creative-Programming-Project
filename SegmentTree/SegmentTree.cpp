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
// セグメントツリー Segment Tree

// 対応ライブラリ Range Minimum Query, Range Max Query, Range Sum Query, Range Update Query, Range Add Query
// verify AOJ DSL_2_A, DSL_2_B, DSL_2_D, DSL_2_E

// RangeMinimumQuery 1点更新(or加算)+区間最小値
template<typename T>
class RangeMinimumQuery {
    private:
        ll SEG_LEN; vector<T>node;
    public:
        RangeMinimumQuery(ll n){
            SEG_LEN = 1LL;
            while(SEG_LEN < n) SEG_LEN *= 2;
            node.resize(2*SEG_LEN,(1LL << 31)-1LL);
            // Range Minimum Queryより
        }
        // RMQと言っても一点更新がupdateなのか加算なのかは不明なため
        void update(ll index, T value){
            index += (SEG_LEN);
            node[index] = value;
            while(index>0){
                index /= 2;
                node[index] = min(node[2*index],node[index*2+1]);
            }
        }
        void add(ll index, T value){
            index += (SEG_LEN);
            node[index] += value;
            while(index>0){
                index /= 2;
                node[index] = min(node[2*index],node[index*2+1]);
            }
        }
        T query(ll l, ll r){
            // [l,r)なのでr++が呼び出す側では必要
            l += SEG_LEN; r += SEG_LEN;
            ll res = (1LL << 31)-1;
            while(l<r){
                // [l,r)区間
                if(l%2==1){
                    chmin(res,node[l]);
                    l++;
                }
                l /= 2;
                if(r%2==1){
                    chmin(res,node[r-1]);
                    r--;
                }
                r /= 2;
            }
            return res;
        }
};
// RangeMaxuery 1点更新(or加算)+区間最大値
template<typename T>
class RangeMaxQuery {
    private:
        ll SEG_LEN; vector<T>node;
    public:
        RangeMaxQuery(ll n){
            SEG_LEN = 1LL;
            while(SEG_LEN < n) SEG_LEN *= 2;
            node.resize(2*SEG_LEN,-(1LL << 31));
            // Range Max Queryより
        }
        // RMQと言っても一点更新がupdateなのか加算なのかは不明なため
        void update(ll index, T value){
            index += (SEG_LEN);
            node[index] = value;
            while(index>0){
                index /= 2;
                node[index] = max(node[2*index],node[index*2+1]);
            }
        }
        void add(ll index, T value){
            index += (SEG_LEN);
            node[index] += value;
            while(index>0){
                index /= 2;
                node[index] = min(node[2*index],node[index*2+1]);
            }
        }
        T query(ll l, ll r){
            // [l,r)なのでr++が呼び出す側では必要
            l += SEG_LEN; r += SEG_LEN;
            ll res = -(1LL << 31);
            while(l<r){
                // [l,r)区間
                if(l%2==1){
                    chmax(res,node[l]);
                    l++;
                }
                l /= 2;
                if(r%2==1){
                    chmax(res,node[r-1]);
                    r--;
                }
                r /= 2;
            }
            return res;
        }
};
// RangeSumQuery 1点更新(or加算)+区間和（デフォルト値設定できる）
template<typename T>
class RangeSumQuery {
    private:
        ll SEG_LEN; vector<T>node;
    public:
        RangeSumQuery(ll n, T value=0){
            // 初期値をセットできるがデフォルト値は0
            SEG_LEN = 1LL;
            while(SEG_LEN < n) SEG_LEN *= 2;
            node.resize(2*SEG_LEN,value);
        }
        void update(ll index, T value){
            index += SEG_LEN;
            node[index] = value;
            while(index > 0){
                index /= 2;
                node[index] = node[2*index] + node[2*index+1];
                // MODをつけるならここ
            }
        }
        void add(ll index, T value){
            index += SEG_LEN;
            node[index] += value;// MODをつけるならここ
            while(index > 0){
                index /= 2;
                node[index] = node[2*index] + node[2*index+1];// MODをつけるならここ
            }
        }
        T query(ll l,ll r){
            // [l,r)なので呼び出す側はr++必要
            l += SEG_LEN; r += SEG_LEN;
            T res = 0;
            while(l<r){
                if(l%2==1){
                    res += node[l];// MODをつけるならここ
                    l++;
                }
                l /= 2;
                if(r%2==1){
                    res += node[r-1];// MODをつけるならここ
                    r--;
                }
                r /= 2;
            }
            return res;
        }
};
// RangeUpdateQuery 範囲更新+一点取得
template<typename T>
class RangeUpdateQuery {
    private:
        ll SEG_LEN; vector<pair<ll,T>>node;
        ll t = 0;
    public:
        RangeUpdateQuery(ll n, T value=(1LL << 31)-1){
            // デフォルト値が設定できる
            SEG_LEN = 1LL;
            while(SEG_LEN < n) SEG_LEN *= 2;
            node.resize(2*SEG_LEN,{0LL,value});
        }
        T query(ll index){
            index += SEG_LEN;
            pair<ll,T> res = node[index];
            while(index>0){
                index /= 2;
                chmax(res,node[index]);// pair(a,b)ではaの値が大きいものが優先される。
            }
            return res.second;
        }
        void update(int l, int r, T value){
            // 区間更新 [l,r)なのでr++が必要
            l += SEG_LEN; r += SEG_LEN; t++;//更新回数
            while(l<r){
                if(l%2==1){
                    node[l] = {t,value};
                    l++;
                }
                l /= 2;
                if(r%2==1){
                    node[r-1] = {t,value};
                    r--;
                }
                r /= 2;
            }
        }
};
// RangeAddQuery 範囲加算+一点取得 上のRangeUpdateQueryと統合することができなかった。
template<typename T>
class RangeAddQuery {
    private:
        ll SEG_LEN; vector<T>node;
    public:
        RangeAddQuery(ll N, T value=0){
            // デフォルト値が設定できる
            SEG_LEN = 1LL;
            while(SEG_LEN < N) SEG_LEN *= 2;
            node.resize(2*SEG_LEN,value);
        }
        T query(ll index){
            // 1点取得
            index += SEG_LEN;
            T res = node[index];
            while(index > 0){
                index /= 2;
                res += node[index];
            }
            return res;
        }
        void add(ll l, ll r, T value){
            // [l,r)の区間 呼び出す側ではr++をする必要がある
            l += SEG_LEN; r += SEG_LEN;
            while(l<r){
                if(l%2==1){
                    node[l] += value;
                    l++;
                }
                l /= 2;
                if(r%2==1){
                    node[r-1] += value;
                    r--;
                }
                r /= 2;
            }
        }
};

int main(){
    ll N,Q;
    cin >> N >> Q;
    RangeAddQuery<ll> sg(N);
    for(int q=0;q<Q;q++){
        ll com;
        cin >> com ;
        if(com == 0){
            ll l, r, x;
            cin >> l >> r >> x;
            sg.add(l,r+1,x);
        }
        else{
            ll index;
            cin >> index;
            cout << sg.query(index) << endl;
        }
    }
}