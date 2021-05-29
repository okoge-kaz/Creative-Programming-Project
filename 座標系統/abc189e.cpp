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
struct matrix {
    ll m11; ll m12; ll m13;
    ll m21; ll m22; ll m23;
    ll m31; ll m32; ll m33;
};
int main(){
    ll N; cin >> N;
    vector<ll>X(N), Y(N);
    for(int i=0;i<N;i++) cin >> X[i] >> Y[i];
    ll M; cin >> M; vector<pair<ll,ll>>op(M);
    for(int i=0;i<M;i++){
        cin >> op[i].first;
        if(op[i].first==3 || op[i].first==4) cin >> op[i].second;
    }
    ll Q; cin >> Q; vector<ll>A(Q), B(Q);
    for(int i=0;i<Q;i++) cin >> A[i] >> B[i];

    vector<matrix>sum(M+1); // sum[0] = E
    sum[0].m11 = 1; sum[0].m22 = 1; sum[0].m33 = 1;
    sum[0].m12 = 0; sum[0].m13 = 0; sum[0].m21 = 0;
    sum[0].m23 = 0; sum[0].m31 = 0; sum[0].m32 = 0;
    // 単位行列を定義

    // 累積積を考える
    for(int i=0;i<M;i++){
        if(op[i].first==1){
            // - 90度
            sum[i+1].m11 = - sum[i].m12;
            sum[i+1].m12 = sum[i].m11;
            sum[i+1].m13 = sum[i].m13;
            sum[i+1].m21 = - sum[i].m22;
            sum[i+1].m22 = sum[i].m21;
            sum[i+1].m23 = sum[i].m23;
            sum[i+1].m31 = - sum[i].m32;
            sum[i+1].m32 = sum[i].m31;
            sum[i+1].m33 = sum[i].m33;
        }
        if(op[i].first==2){
            // +90度
            sum[i+1].m11 = sum[i].m12;
            sum[i+1].m12 = - sum[i].m11;
            sum[i+1].m13 = sum[i].m13;
            sum[i+1].m21 = sum[i].m22;
            sum[i+1].m22 = - sum[i].m21;
            sum[i+1].m23 = sum[i].m23;
            sum[i+1].m31 = sum[i].m32;
            sum[i+1].m32 = - sum[i].m31;
            sum[i+1].m33 = sum[i].m33;
        }
        if(op[i].first==3){
            // x = p
            sum[i+1].m11 = - sum[i].m11;
            sum[i+1].m12 = sum[i].m12;
            sum[i+1].m13 = sum[i].m13 + 2*op[i].second * sum[i].m11;
            sum[i+1].m21 = - sum[i].m21;
            sum[i+1].m22 = sum[i].m22;
            sum[i+1].m23 = sum[i].m23 + 2*op[i].second * sum[i].m21;
            sum[i+1].m31 = - sum[i].m31;
            sum[i+1].m32 = sum[i].m32;
            sum[i+1].m33 = sum[i].m33 + 2*op[i].second * sum[i].m31;
        }
        if(op[i].first==4){
            // y = p
            sum[i+1].m11 = sum[i].m11;
            sum[i+1].m12 = - sum[i].m12;
            sum[i+1].m13 = sum[i].m13 + 2*op[i].second * sum[i].m12;
            sum[i+1].m21 = sum[i].m21;
            sum[i+1].m22 = - sum[i].m22;
            sum[i+1].m23 = sum[i].m23 + 2*op[i].second * sum[i].m22;
            sum[i+1].m31 = sum[i].m31;
            sum[i+1].m32 = - sum[i].m32;
            sum[i+1].m33 = sum[i].m33 + 2*op[i].second * sum[i].m32;
        }
    }
    //
    for(int i=0;i<Q;i++){
            ll x = X[B[i]-1]; ll y = Y[B[i]-1];
            ll ans_x = sum[A[i]].m11 * x + sum[A[i]].m12 * y + sum[A[i]].m13 ;
            ll ans_y = sum[A[i]].m21 * x + sum[A[i]].m22 * y + sum[A[i]].m33 ;
            cout << ans_x << " " << ans_y << endl;
    }
}