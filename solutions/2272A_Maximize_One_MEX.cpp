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
    int n, k;
    cin >> n >> k;
    
    vector <int> a(n + 1, 0);
    vector <int> pos(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
 
    int ans = 1;
    vector <bool> visited(n + 1, false);
    for (int i = 1; i <= n - k + 1; i++) {
        visited[a[i]] = true;
        if (a[i] > a[ans]) {
            ans = i;
        }
    }
 
    int mex = 0;
    while (visited[mex] == true) {
        ++mex;
    }
 
    if (mex >= n - k + 1) {
        cout << -1 << '\n';
    }
    else {
        cout << ans << ' ' << pos[mex] << '\n';
    }
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