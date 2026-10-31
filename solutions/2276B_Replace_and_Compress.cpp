#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
#define all(x) begin(x), end(x)
#define sz(x) static_cast<int>((x).size())
 
template<class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
 
void solve() {
    string s;
    cin >> s;
 
    bool check_1 = false, check_2 = false;
    for (int i = 1; i < (int) s.size() - 1; i++) {
        if (s[i - 1] == s[i + 1]) {
            if (s[i] == s[i - 1]) {
                check_1 = true;   
            } 
            else {
                check_2 = true;  
            }
        }
    }
    cout << check_1 + check_2 + 1 << '\n';
}
 
int main() {
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1;
    cin >> t;
 
    while (t--) {
        solve();
    }
 
    return 0;
}