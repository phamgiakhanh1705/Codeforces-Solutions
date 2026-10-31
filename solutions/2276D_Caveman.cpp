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
    int n, m;
    cin >> n >> m;
 
    vector <int> deg(n + 1, 0);
 
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
 
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            cout << "Brain Melt" << '\n';
            return;
        }
        chmax(mx, deg[i]);
    }
 
    if (m == n - 1 && mx == n - 1) {
        cout << 2 << '\n';
    } 
    else {
        cout << "Many" << '\n';
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