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

string modify(int num){
    // 6 文字になるまで０を左側に挿入し続ける関数
    string tmp = to_string(num);
    int n = tmp.size();
    if(n==6) return tmp;
    else{
        while(tmp.size()!=6){
            tmp = '0' + tmp;
        }
        return tmp;
    }
}

int main(){
    // input
    int N,M;
    cin >> N >> M;
    vector<int>P(M), Y(M);
    for(int i=0;i<M;i++) cin >> P[i] >> Y[i];
    vector<pair<int,string>>ans;

    map<int,int>data;
    vector<pair<int,pair<int,int>>>Year_Pref;
    for(int i=0;i<M;i++) Year_Pref.push_back({Y[i],{P[i],i}});
    sort(Year_Pref.begin(),Year_Pref.end());// 成立年月日順にsortする

    for(auto[year,pi]:Year_Pref){
        data[pi.first]++;
        string tmp = modify(pi.first) + modify(data[pi.first]);
        ans.push_back({pi.second,tmp});
    }
    sort(ans.begin(),ans.end());
    for(auto[i,id]:ans) cout << id << endl;
    // なにかアルゴリズムが難しいとかそういうわけではなく、単純に処理が面倒
}