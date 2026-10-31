#include <bits/stdc++.h>
using namespace std;
 
int calc(int x) {
    if(x < 2) return 0;
    int i = 31 - __builtin_clz(x - 1);
    return (x == (1 << i) ? (1 << i) - 1 : (1 << (i + 1)) - 1);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n , x; cin >> n >> x;
        int val = 0;
        for(int i = 0; i <= n; i++) {
            if(i) {
                int cur = calc(i);
                if(~((~cur) | x)) continue;
                int tmp = (cur == x ? i : i + 1);
                if(tmp <= n) val = i;
            }
            else val = 0;
        }
        vector <int> vec = {};
        if(val) {
            for(int i = 0; i < val; i++) {
                vec.push_back(i);
            }
            int cur = calc(val);
            if(cur - x) {
                vec.push_back(x & (~cur));
            }
        }
        else vec.push_back(x);
        vector <int> res = {};
        for(int x : vec) {
            res.push_back(x);
        }
        while((int) res.size() < n) {
            res.push_back((val > 0 ? 0 : x));
        }
        for(int i = 0; i < n; i++) cout << res[i] << ' ';
        cout << '\n';
    }
}