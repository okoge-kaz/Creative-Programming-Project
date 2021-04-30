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

// https://atcoder.jp/contests/abc114/tasks/abc114_c
// 上記の回答
ll N;
ll dfs(string &s){
    ll res = 0;
    vector<char>lis = {'3','5','7'};
    if(!s.empty()){
        // stollを使うときは,stringが空であることを排除していないとsegmentation faultになる
        if(stoll(s) > N)return res;//これがベースケース
        else{
            bool flag = true;
            for(auto c:lis){
                if(s.find(c)==string::npos) flag = false;
                // .find() methodは、見つからなかった場合 string::nposを返す
            }
            if(flag) res++;
        }
        //ここからが真髄
        for(char c:lis){
            s.push_back(c);
            res += dfs(s);
            s.pop_back();//元に戻している
        }
    }
}