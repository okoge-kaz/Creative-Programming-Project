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
struct ability{
    ll a;
    ll b;
    ll c;
    ll d;
    ll e;
};
int N;
vector<pair<ll,int>>A,B,C,D,E;
vector<ll>A1,B1,C1,D1,E1;
bool is_OK(ll x, vector<vector<ability>>&data){
    ll tmp=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            vector<ll>num;
            num = {data[i][j].a,data[i][j].b,data[i][j].c,data[i][j].d,data[i][j].e};
            sort(num.begin(),num.end());
            chmax(tmp ,num[0]);
            if(data[i][j].a==num[0]){
                if(upper_bound(A.begin(),A.end(),num[0])!=A.end()){
                    int itr = upper_bound(A.begin(),A.end(),num[0]) - A.begin();
                    chmax(data[i][j].a ,A1[itr]);
                    chmax(data[i][j].b ,B1[itr]);
                    chmax(data[i][j].c ,C1[itr]);
                    chmax(data[i][j].d ,D1[itr]);
                    chmax(data[i][j].e ,E1[itr]);
                    num = {data[i][j].a,data[i][j].b,data[i][j].c,data[i][j].d,data[i][j].e};
                    sort(num.begin(),num.end());
                    chmax(tmp,num[0]);
                }
            }
            if(data[i][j].b==num[0]){
                if(upper_bound(B.begin(),B.end(),num[0])!=B.end()){
                    int itr = upper_bound(B.begin(),B.end(),num[0]) - B.begin();
                    chmax(data[i][j].a ,A1[itr]);
                    chmax(data[i][j].b ,B1[itr]);
                    chmax(data[i][j].c ,C1[itr]);
                    chmax(data[i][j].d ,D1[itr]);
                    chmax(data[i][j].e ,E1[itr]);
                    num = {data[i][j].a,data[i][j].b,data[i][j].c,data[i][j].d,data[i][j].e};
                    sort(num.begin(),num.end());
                    chmax(tmp,num[0]);
                }
            }
            if(data[i][j].c==num[0]){
                if(upper_bound(C.begin(),C.end(),num[0])!=C.end()){
                    int itr = upper_bound(C.begin(),C.end(),num[0]) - C.begin();
                    chmax(data[i][j].a ,A1[itr]);
                    chmax(data[i][j].b ,B1[itr]);
                    chmax(data[i][j].c ,C1[itr]);
                    chmax(data[i][j].d ,D1[itr]);
                    chmax(data[i][j].e ,E1[itr]);
                    num = {data[i][j].a,data[i][j].b,data[i][j].c,data[i][j].d,data[i][j].e};
                    sort(num.begin(),num.end());
                    chmax(tmp,num[0]);
                }
            }
            if(data[i][j].d==num[0]){
                if(upper_bound(D.begin(),D.end(),num[0])!=D.end()){
                    int itr = upper_bound(D.begin(),D.end(),num[0]) - D.begin();
                    chmax(data[i][j].a ,A1[itr]);
                    chmax(data[i][j].b ,B1[itr]);
                    chmax(data[i][j].c ,C1[itr]);
                    chmax(data[i][j].d ,D1[itr]);
                    chmax(data[i][j].e ,E1[itr]);
                    num = {data[i][j].a,data[i][j].b,data[i][j].c,data[i][j].d,data[i][j].e};
                    sort(num.begin(),num.end());
                    chmax(tmp,num[0]);
                }
            }
            if(data[i][j].e==num[0]){
                if(upper_bound(E.begin(),E.end(),num[0])!=E.end()){
                    int itr = upper_bound(E.begin(),E.end(),num[0]) - E.begin();
                    chmax(data[i][j].a ,A1[itr]);
                    chmax(data[i][j].b ,B1[itr]);
                    chmax(data[i][j].c ,C1[itr]);
                    chmax(data[i][j].d ,D1[itr]);
                    chmax(data[i][j].e ,E1[itr]);
                    num = {data[i][j].a,data[i][j].b,data[i][j].c,data[i][j].d,data[i][j].e};
                    sort(num.begin(),num.end());
                    chmax(tmp,num[0]);
                }
            }
        }
    }
    if(tmp <= x) return true;
    else return false;
}
int main(){
    cin >> N;
    A.resize(N);
    B.resize(N);
    C.resize(N);
    D.resize(N);
    E.resize(N);
    A1.resize(N);
    B1.resize(N);
    C1.resize(N);
    D1.resize(N);
    E1.resize(N);
    for(int i=0;i<N;i++){
        cin >> A[i].first >> B[i].first >> C[i].first >> D[i].first >> E[i].first;
        A[i].second = B[i].second = C[i].second = D[i].second = E[i].second = i;
        A1[i] = A[i].first;
        B1[i] = B[i].first;
        C1[i] = C[i].first;
        D1[i] = D[i].first;
        E1[i] = E[i].first;
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());
    sort(D.begin(),D.end());
    sort(E.begin(),E.end());

    ll ans = 0;
    // 愚直にするとO(N^3)
    vector<vector<ability>>data(N,vector<ability>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            data[i][j].a = max(A[i].first,A[j].first);
            data[i][j].b = max(B[i].first,B[j].first);
            data[i][j].c = max(C[i].first,C[j].first);
            data[i][j].d = max(D[i].first,D[j].first);
            data[i][j].e = max(E[i].first,E[j].first);
        }
    }
    ll ok = INF, ng = -1;
    while(ok - ng > 1){
        ll mid = (ok + ng)/2;
        if(is_OK(mid,data))  ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}