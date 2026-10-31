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
    int n; cin >> n;
    string s, t;
    cin >> s >> t;
 
    int ans = 0;
    for (int i = 0; i < (int) s.size(); i++) ans = (ans + (s[i] == 'f')) % 2;
    for (int i = 0; i < (int) t.size(); i++) ans = (ans + (t[i] == 'f')) % 2;
 
    cout << ans << '\n';
    return;
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