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
    vector<string>ans;
    for(int i=0;i<31;i++){
        string s;
        cin >> s;
        int n = s.size();
        for(int j=0;j<n;j++){
            if('a'<= s[j] && s[j] <= 'm') s[j] = s[j] + 13;
            else s[j] = s[j] - 13;
        }
        ans.push_back(s);
    }
    cout << " " <<  endl;
    for(string s:ans) cout << s << endl;
}