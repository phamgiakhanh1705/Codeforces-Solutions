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
    int k; cin >> k;
    int id = -1, node = -1;
    for (int i = 1; i <= k; i++) {
        int n; cin >> n;
        vector <vector <int>> adj(n + 1);
        for (int j = 1; j < n; j++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if (n < 2 || id != -1) continue;
        id = i;
        
        vector <int> vec = {};
        vec.push_back(1);
        
        vector <int> par(n + 1, 0);
        par[1] = -1;
        
        for (int i = 0; i < (int) vec.size(); i++) {
            int v = vec[i];
            for (int u : adj[v]) {
                if (u != par[v]) {
                    par[u] = v;
                    vec.push_back(u);
                }
            }
        }
 
        vector <vector <int>> dp(n + 1, vector <int> (2, 0));
        for (int i = 1; i <= n; i++) {
            dp[i][1] = 1;
        }
 
        for (int i = n - 1; i >= 1; i--) {
            int v = vec[i];
            int p = par[v];
            dp[p][0] += max(dp[v][0], dp[v][1]);
            dp[p][1] += dp[v][0];
        }
 
        vector <vector <int>> up(n + 1, vector <int> (2, 0));
        for (int i = 1; i < n; i++) {
            int c = vec[i];
            int p = par[c];
            up[c][0] = dp[p][0] - max(dp[c][0], dp[c][1]) + max(up[p][0], up[p][1]);
            up[c][1] = dp[p][1] - dp[c][0] + up[p][0];
        }
 
        for (int i = 1; i <= n; i++) {
            if (dp[i][0] + max(up[i][0], up[i][1]) == max(dp[1][0], dp[1][1])) {
                node = i;
                goto done;
            }
        }
        node = -1;
        done:;
        
    }
 
    if (id == -1) {
        id = node = 1;
    }
 
    for (int i = 1; i <= k; i++) {
        if (i != id) {
            cout << i << ' ' << 1 << ' ' << id << ' ' << node << '\n';
        }
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