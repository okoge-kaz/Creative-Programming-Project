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

bool check(ll mid,vector<ll>&v,ll x){
    if(v[mid] <= x) return true;
    else return false;
}
template<typename T>
int below_bound(vector<T>&vec,T value){
    // value以下になるもので最大のidを取得する(0-index)
    int ok = -1; int ng = (int)vec.size();
    while(abs(ok-ng)>1){
        int mid = (ok+ng)/2;
        if(check(mid,vec,value)) ok = mid;
        else ng = mid;
    }
    return ok;// 1つもない時は-1を返す
}

int main(){
    int N; cin >> N;
    ll T; cin >> T;
    vector<ll>A(N); for(int i=0;i<N;i++) cin >> A[i];
    int mid = N/2;

    vector<ll>vec1;vector<ll>vec2;
    for(int bit=0;bit<(1<<mid);bit++){
        ll acc = 0;
        for(int i=0;i<mid;i++){
            if(bit & (1<<i)) { acc += A[i]; }
        }
        vec1.push_back(acc);
    }
    for(int bit=0;bit<(1<<(N-mid));bit++){
        ll acc = 0;
        for(int i=0;i<(N-mid);i++){
            if(bit & (1<<i)) { acc += A[mid+i]; }
        }
        vec2.push_back(acc);
    }
    sort(vec1.begin(),vec1.end());
    sort(vec2.begin(),vec2.end());
    ll ans = 0;
    for(ll e:vec1){

        // ll ok = 0; ll ng = (int)vec2.size();
        // while(abs(ok-ng)>1){
        //     ll mid = (ok+ng)/2;
        //     if(check(mid,vec2,T-e)) ok = mid;
        //     else ng = mid;
        // }
        // if(vec2[ok] + e <= T) chmax(ans,vec2[ok]+e);
        
        int id = below_bound(vec2,T-e);
        if(id==-1)continue;
        chmax(ans,vec2[id]+e);
    }
    cout << ans << endl;
}