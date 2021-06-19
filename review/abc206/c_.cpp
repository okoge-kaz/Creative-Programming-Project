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
    vector<int>A(N); for(int i=0;i<N;i++) cin >> A[i];
    map<int,vector<int>>data;
    for(int i=0;i<N;i++) data[A[i]].push_back(i);//このように使えるとは自分でもよく知らなかった
    // mapの内部は勝手にソートされるので
    ll ans = 0;
    for(int i=0;i<N;i++){
        ll cnt = N-(i+1);// 自分よりも大きい数
        int id = upper_bound(data[A[i]].begin(),data[A[i]].end(),i) - data[A[i]].begin();
        cnt -= ((int)data[A[i]].size() - id);// 自分より大きいところにある数
        ans += cnt;
    }
    cout << ans << endl;
}