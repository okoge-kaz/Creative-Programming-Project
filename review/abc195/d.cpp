#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
const long long INF = 1LL << 60;
const ll mod = 998244353;
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// 変数
int N,M,Q;
// L,Rが与えられて、答えを返す関数
ll calc(ll L,ll R ,vector<ll> &X, vector<pair<ll,ll>> vw){
    // vector<ll>Xに関して、参照渡しにした理由 (& )
    // vector<ll>X の値を編集しないので、値渡しにする必要性がない
    ll res = 0;// 返り値
    // 使える範囲のxを集めた配列をつくる
    vector<ll>x;
    for(int i=0;i<M;i++){
        if(L <= i && i <= R) continue;
        else x.emplace_back(X[i]);
    }
    // 二分探索を使いたい
    sort(x.begin(),x.end());// sortする
    for(auto [value, weight]:vw){
        if(x.empty())break;// もう箱がない
        auto id = lower_bound(x.begin(),x.end(),weight);
        // vw の中から価値の高い順に考えていく
        if(id == x.end())continue;// 見つからないとき
        // 見つかった時
        res += value;
        // その箱は使えないので削除する
        x.erase(id);
    }
    return res;

}

int main(){
    // input
    cin >> N >> M >> Q;
    // 荷物には大きさと価値が紐づいているのでpairとる
    vector<pair<ll,ll>>vw(N);
    for(int i=0;i<N;i++) cin >> vw[i].second >> vw[i].first;
    // 貪欲法を想定している。
    // この後で、価値が大きいものを優先して使いたい（＝貪欲）
    sort(vw.begin(),vw.end(),greater<>());
    // 価値 v が大きい順（貪欲法を見据えて）
    vector<ll>X(M);
    for(int i=0;i<M;i++) cin >> X[i];
    // この配列はsortできない
    // なぜならば、この後で与えられるクエリは L <= i <= R の形で与えられるので
    
    // クエリ
    for(int i=0;i<Q;i++){
        int L,R;
        cin >> L >> R;
        // 注意：0-indexなのでL,Rを適切に処理
        --L,--R;
        cout << calc(L,R,X,vw) << endl;
    }
    // 計算量は、前処理で一番大きいのがsortなので O(N lon(N))かかっていて
    // 関数の中身は sortで O(M long(M)), 探索で O(N log(M))かかっている
    // また、クエリが Q 回あり、関数はそれだけ呼び出されるので、全体で O(Q * N * long(M))ぐらいかかる
}