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

int N; vector<int>w; vector<vector<int>>dp;

int calc(int l=0,int r=N){
    // [l,r)
    if((r-l)<=1) return 0;// r-lと書くのは、再帰関数の終了地点として機能させるため
    if((r-l)==2){
        if(abs(w[l]-w[l+1])<=1) return 2;
        else return 0;
    }
    int &res = dp[l][r];// 参照型にする
    if(res != -1) return res;// メモ化再帰

    // すべて取り除けるとき
    if(abs(w[l]-w[r-1])<=1 && calc(l+1,r-1)==(r-1-(l+1))){
        // 新たに範囲に入った端も差が１以下であり && 新たに入った部分を除いた部分もすべて取り除くことができるのならば
        chmax(res,r-l);
    }
    // そうでないとき
    for(int i=l+1;i<=r-1;i++){
        chmax(res,calc(l,i)+calc(i,r));
    }
    return res;
}

int main(){
    vector<int>ans;
    while(true){
        cin >> N;
        if(N==0) break;
        w.resize(N);
        for(int i=0;i<N;i++) cin >> w[i];
        dp.assign(N+2,vector<int>(N+2,-1));

        ans.push_back(calc());
    }

    for(int &e:ans) cout << e << endl;
}