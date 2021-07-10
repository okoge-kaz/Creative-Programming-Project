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
    int N; cin >> N;
    string S; cin >> S;
    vector<int>O,X;
    for(int i=0;i<N;i++){
        if(S[i]=='o') O.push_back(i);
        else X.push_back(i);
    }
    sort(O.begin(),O.end()); sort(X.begin(),X.end());

    ll ans = 0;
    for(int i=0;i<N;i++){
        if(S[i]=='o'){
            auto id = (upper_bound(X.begin(),X.end(),i));
            if(id==X.end()) continue;
            ans += (N - X[(id - X.begin())]);
        }
        else{
            auto id = upper_bound(O.begin(),O.end(),i);
            if(id==O.end())continue;
            ans += (N - O[(id-O.begin())]);
        }
    }
    cout << ans << endl;
}