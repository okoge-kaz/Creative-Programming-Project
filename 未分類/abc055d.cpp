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
using lll = __int128_t;
int main(){
    int N; cin >> N;
    string S; cin >> S;
    vector<vector<char>>data(4,vector<char>(N,'-'));// stringにすると空になってメモリが確保されないので
    data[0][0] = 'S', data[0][1] = 'S';
    data[1][0] = 'S', data[1][1] = 'W';
    data[2][0] = 'W', data[2][1] = 'S';
    data[3][0] = 'W', data[3][1] = 'W';

    for(int i=0;i<4;i++){
        bool flg = true;
        for(int j=0;j<N;j++){
            if(data[i][j]=='S'){
                int prev = j-1; int next = j+1;
                if(prev < 0) prev = N-1;
                if(next >= N) next = 0;
                if(S[j]=='o'){
                    if(data[i][prev] == '-') data[i][prev] = data[i][next];
                    else if(data[i][next] == '-') data[i][next] = data[i][prev];
                    //
                    if(data[i][next]!=data[i][prev]) flg = false;
                }
                else{
                    if(data[i][prev] == '-') data[i][prev] = data[i][next]=='S'? 'W' : 'S';
                    else if(data[i][next] == '-') data[i][next] = data[i][prev]=='S'? 'W': 'S';
                    //
                    if(data[i][next]==data[i][prev]) flg = false;
                }
            }
            else{
                int prev = j-1; int next = j+1;
                if(prev < 0) prev = N-1;
                if(next >= N) next = 0;
                if(S[j]=='x'){
                    if(data[i][prev] == '-') data[i][prev] = data[i][next];
                    else if(data[i][next] == '-') data[i][next] = data[i][prev];
                    //
                    if(data[i][next]!=data[i][prev]) flg = false;
                }
                else{
                    if(data[i][prev] == '-') data[i][prev] = data[i][next]=='S'? 'W' : 'S';
                    else if(data[i][next] == '-') data[i][next] = data[i][prev]=='S'? 'W': 'S';
                    //
                    if(data[i][next]==data[i][prev]) flg = false;
                }
            }
        }
        if(flg){
            for(char c:data[i]) cout << c ;
            cout << endl; return 0;
        }
    }
    cout << -1 << endl;
}