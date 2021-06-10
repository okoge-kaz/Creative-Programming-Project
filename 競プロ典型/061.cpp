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

template<class T>
class Deque {
    private:
        int size; int cl; int cr; vector<T>nums;
    public:
        Deque<T>(int size) : size(size) ,cl(size) ,cr(size), nums(2*size,0) {}
        void push_front(T x){
            cl--;
            nums[cl] = x;
        }
        void push_back(T x){
            nums[cr] = x;
            cr++;
        }
        void pop_back(T x){
            cr--;
            nums[cr] = 0;
        }
        void pop_front(T x){
            nums[cl] = 0;
            cl++;
        }
        T at(int id){
            return nums[cl+id];
        }
};

int main(){
    int Q; cin >> Q;
    // dequeを自分で実装することでランダムアクセスを可能とする
    // Deque<ll>que(100000);
    deque<ll>que;
    for(int i=0;i<Q;i++){
        int t; ll x; cin >> t >> x;
        if(t==1) que.push_front(x);
        if(t==2) que.push_back(x);
        if(t==3){
            cout << que[x-1] << endl;
        }
    }
}