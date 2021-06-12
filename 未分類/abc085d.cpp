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
    ll N, H; cin >> N >> H;
    vector<ll>a(N), b(N); for(int i=0;i<N;i++) cin >> a[i] >> b[i];
    // ナップザック（0,1ナップザック＋個数制限なしナップザック）ではHが大きすぎて解けない
    // 貪欲に解ける
    ll a_max = 0;
    for(int i=0;i<N;i++) chmax(a_max,a[i]);
    vector<ll>c; 
    for(int i=0;i<N;i++){
        if(b[i]>=a_max) c.push_back(b[i]); 
    }
    sort(c.begin(),c.end(),greater<ll>());
    ll cnt = 0;
    // どうせ最後は投げるのだから、投げたものとして事前にカウントしておけば良い
    for(ll e:c){
        if(H<=0){
            cout << cnt << endl;
            return 0;
        }
        H -= e; cnt++;
    }
    if(H>0){
        if(H%a_max==0) cnt += H/a_max;
        else cnt += H/a_max + 1;
    }
    cout << cnt << endl;
}