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
int main(){
    // input
    string s;
    cin >> s;
    int N = s.size();
    int K;
    cin >> K;

    // 愚直にするとなると、O(N^3)かかるので間に合わない
    // 着目するべきは、1<= K <= 5 の部分
    set<string>subst;
    for(int i=0;i<N;i++){
        for(int k=1;k<=K;k++){
            if(i+k-1 >= N) continue;
            subst.insert(s.substr(i,k));
        }
    }
    // substr は、計算量がO(N)なので注意
    // 上記のポイントは計算量をO(N*N*K)に抑えられることにある。
    // K番目に小さいものなので、必ずK番目に来るものは、K文字よりも小さい
    vector<string>sub;
    for(string s:subst) sub.push_back(s);
    sort(sub.begin(),sub.end());
    cout << sub[K-1] << endl;
}