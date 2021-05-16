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
int main(){
    // 2 分探索とわかっても、その後の処理の仕方が難しい
    // https://atcoder.jp/contests/zone2021/editorial/1197
    int N;
    cin >> N;
    vector<vector<ll>>ABCDE(N,vector<ll>(5));
    for(int i=0;i<N;i++) for(int j=0;j<5;j++) cin >> ABCDE[i][j];
    ll ok = 0, ng = 1000000001;// 1 <= (能力値) <= 1e9 なので、それを開区間で含むような範囲を考える
    
    // c++ のラムダ式
    auto check = [&](ll x) -> bool {
        set<int>s;
        for(auto& abcde: ABCDE){
            int bit = 0;// このような分かりにくい書き方をするのは、範囲for文にするため
            for(ll i: abcde){
                bit <<= 1;//  bit = bit << 1 のこと
                bit |= i >= x;
            }
            s.insert(bit);// 各人の能力がx以上の数値かいないかをbit化し、setに入れる
        }
        // 3人を選ぶの３重ループ
        for(int a: s) for(int b: s) for(int c: s){
            if((a | b | c ) == ((1 << 5) -1 )) return true;
        }
        return false;
    };

    while(abs(ok - ng) > 1){
        ll mid = (ok + ng)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}