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
// decleration
int N,K;
vector<ll>w,p;
vector<pair<ll,ll>>pw;
// judge
bool check(ld x){
    // ここが難しい
    vector<ld>tmp(N);
    for(int i=0;i<N;i++){
        tmp[i] = (p[i]-x)*(w[i]);// 余る塩の量
    }
    sort(tmp.begin(),tmp.end(),greater<ld>());
    ll salt=0;
    for(int i=0;i<K;i++) salt+=tmp[i];
    if(salt >= 0) return true;
    else return false;
}
int main(){
    cout << std::fixed << std::setprecision(15) ;
    // input
    cin >> N >> K;
    w.resize(N); p.resize(N);
    for(int i=0;i<N;i++) cin >> w[i] >> p[i];
    // sort
    pw.resize(N);
    for(int i=0;i<N;i++) pw[i].first = p[i], pw[i].second = w[i];
    sort(pw.begin(),pw.end(),greater<pair<ll,ll>>());
    // binary search
    ld ok = 0; ld ng = 101;
    for(int i=0;i<=1000;i++){
        ld mid = (ok+ng)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    // ans
    cout << ok << endl;
}