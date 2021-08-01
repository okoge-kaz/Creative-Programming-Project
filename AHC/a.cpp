#include <bits/stdc++.h>
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

const int MAX_TIME = 2000000;
// variable
int D;
vector<ll>c(26);
vector<vector<ll>>s;
vector<ll>t;
clock_t start;
ll old_evaluation_score;

void input(){
    start = clock();
    // input
    cin >> D;
    for(int i=0;i<26;i++) cin >> c[i];
    s.resize(D,vector<ll>(26));
    for(int i=0;i<D;i++){
        for(int j=0;j<26;j++){
            cin >> s[i][j];
        }
    }
}

ll calculateScore(vector<ll>&t){
    ll res = 0;
    vector<int>last(26,0);
    for(int i=0;i<D;i++){
        res += s[i][t[i]-1];
        // 満足度の低下
        last[t[i]-1] = i+1;
        for(int j=0;j<26;j++){
            res -= c[j] * (i+1 - last[j]);
        }
    }
    return res;
}

void calc(){
    while( (clock()-start) < 0.95 * MAX_TIME){
        //山登り法

        // if(random()%2==0){
        //     // 1点 更新
        //     int id = random() % D;
        //     int old_value = t[id];
        //     t[id] = random() % 26 + 1;// ここはあとで引くので
        //     if(!chmax(old_evaluation_score,calculateScore(t))){
        //         t[id] = old_value;
        //     }
        // }
        // else{
        //     // 2点間 swap
        //     int id1 = random() % D;
        //     int id2 = random() % D;
        //     swap(t[id1],t[id2]);
        //     if(!chmax(old_evaluation_score,calculateScore(t))){
        //         swap(t[id1],t[id2]);    
        //     }
        // }

        double per = 1.0 * (clock() - start)/MAX_TIME;
        // ここは自分で決める
        const double T0 = 2000; const double T1 = 600;
        double T = pow(T0,1-per) * pow(T1,per);
        double R = (random() % 10000) * 1.0 /1000;
        
        if(random()%2==0){
            // 1点 更新
            int id = random() % D;
            int old_value = t[id];
            t[id] = random() % 26 + 1;// ここはあとで引くので
            ll new_evaluation_score = calculateScore(t);
            if(!chmax(old_evaluation_score,new_evaluation_score)){
                ll Diff = new_evaluation_score-old_evaluation_score;
                double select = pow(2,Diff/T);
                if(select > R) continue;
                t[id] = old_value;
            }
        }
        else{
            // 2点間 swap
            int id1 = random() % D;
            int id2 = random() % D;
            swap(t[id1],t[id2]);
            ll new_evaluation_score = calculateScore(t);
            if(!chmax(old_evaluation_score,new_evaluation_score)){
                ll Diff = new_evaluation_score-old_evaluation_score;
                double select = pow(2,Diff/T);
                cerr << "probability: " << select << endl;
                if(select > R) continue;
                swap(t[id1],t[id2]);    
            }
        }

        // 結果を確認
        cerr << "score: " << calculateScore(t) << endl;
        
    }
}

void output(){
    for(auto e:t) cout << e << endl;
}

int main(){
    input();
    t.assign(D,1);// 初期値
    old_evaluation_score = calculateScore(t);
    calc();
    output();
}