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
    int N;
    cin >> N;
    vector<int>line(N);
    for(int i=0;i<N;i++) line[i] = i;
    ll ans = INF;
    vector<vector<int>>A(N,vector<int>(N));
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) cin >> A[i][j];
    int M;
    cin >> M;
    vector<int>X(M),Y(M);
    for(int i=0;i<M;i++){
        int x, y;
        cin >> x >> y;
        --x,--y;
        X[i] = x , Y[i] = y;
    }
    vector<set<int>>dislike(N);
    for(int i=0;i<M;i++){
        dislike[X[i]].insert(Y[i]);
        dislike[Y[i]].insert(X[i]);
    }

    do {
        ll tmp = 0;
        int last = -1;
        for(int j=0;j<N;j++){
            // j区画を走るi選手
            int i=line[j];
            if(dislike[i].end()!= dislike[i].find(last)){
                // 見つかったら
                tmp = INF;
                chmin(ans,tmp);
                break;
            }
            tmp += A[i][j];
            last = i;
        }
        chmin(ans,tmp);
    } while (std::next_permutation(line.begin(), line.end()));

  if(ans==INF) cout << -1 << endl;
  else cout << ans << endl;
}