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
ll N;
bool seen[200];
vector<ll>mod_A;
void dfs(int d, int i,int ex,set<ll>&tmp,vector<vector<set<ll>>>&ans){
    if(d>N) return;
    seen[mod_A[i]]=true;
    tmp.insert(i);
    //
    ex += mod_A[i];
    ex %= 200;
    ans[ex].push_back(tmp);
    for(int i=0;i<N;i++){
        if(!seen[mod_A[i]]) dfs(d+1,i,ex,tmp,ans);
    }
    //
    tmp.erase(i);
    seen[mod_A[i]]=false;
}
int main(){
    cin >> N;
    vector<ll>A(N);
    for(int i=0;i<N;i++) cin >> A[i];

    mod_A.resize(N);
    map<ll,ll>data;
    for(int i=0;i<N;i++){
        mod_A[i] = A[i] % 200;
        data[mod_A[i]]++;
    }

    for(auto [value,cnt]:data){
        if(cnt > 1){
            int x = 1, y = 1;
            int b=-1,c=-1;
            for(int i=0;i<N;i++){
                if(b==-1 && A[i]%200==value) b = i;
                else if(A[i]%200 == value) c = i;
            }
            cout << "Yes" << endl;
            cout << x << " " << b+1 << endl;
            cout << y << " " << c+1 << endl;
            return 0;
        }
    }
    // cnt <= 1の場合
    // 以降、mod_Aしか考えなくて良い
    // どうせ cnt == 1なのだから
    vector<vector<set<ll>>>ans(200);
    for(int i=0;i<N;i++){
        set<ll>tmp;
        dfs(1,i,0,tmp,ans);
    }
    for(int i=0;i<200;i++){
        ans[i].erase(unique(ans[i].begin(),ans[i].end()),ans[i].end());
    }
    for(int i=0;i<200;i++){
        if((int)ans[i].size()>1){
            cout << "Yes" << endl;
            int x = ans[i][0].size();
            int y = ans[i][1].size();
            cout << x << " ";
            for(auto n:ans[i][0]) cout << n+1 << " ";
            cout << endl;
            cout << y << " ";
            for(auto n:ans[i][1]) cout << n+1 << " ";
            cout << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}