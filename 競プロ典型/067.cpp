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
string to_K(ll k,ll n){

    string s;
    while(n){// 0になったら終了
        s = to_string(n%k) + s;// このように書くことで下の桁から埋めていくことが可能になる．
        n /= k;
    }
    return s;
}

string From_k_To_l (string num, int k,int l){
    // k進数をl進数に変換する関数
    // ただし 1 <= k <= 10 && 1 <= l << 10 
    ll tmp = 0;
    int cnt = 0;
    for(int i=(int)num.size()-1;i>=0;i--){
        tmp +=  (num[i]-'0') * (ll)pow(k,cnt);
        cnt++;
    }
    // 10進数になった。
    if(tmp == 0) return "0";
    string res;
    while(tmp){
        res = to_string(tmp%l) + res;
        tmp /= l;
    }
    return res;
}

// 8進数を10進数に直す
string calc(string n){
    ll res=0; int i=0; 
    reverse(n.begin(),n.end());
    for(char c:n){
        res += (c-'0')*(ll)pow(8,i);
        i++;
    }
    // cout << res << endl;
    return to_string(res);
}

int main(){
    string N; cin >> N;
    int K; cin >> K;
    // if(N=="0"){
    //     cout << 0 << endl;
    //     return 0;
    // }
    // for(int i=0;i<K;i++){ 
    //     N = calc(N);
    //     // cout << N << endl;
    //     string tmp = to_K(9,stol(N));
    //     for(char &c:tmp) if(c =='8') c = '5';
    //     N = tmp;
    // }
    // cout << N << endl;

    for(int i=0;i<K;i++){
        N = From_k_To_l(N,8,9);
        for(char &c:N) if(c=='8') c = '5';
    }
    cout << N << endl;
}