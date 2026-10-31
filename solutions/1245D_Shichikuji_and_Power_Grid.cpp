#include <bits/stdc++.h>
#define int long long
using namespace std;
 
const int N = 2e3 + 5;
 
vector <pair <int, int>> adj[N];
 
int32_t main() {
    int n; cin >> n;
    vector <pair <int, int>> points(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> points[i].first >> points[i].second;
    }
 
    vector <int> c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    
    vector <int> k(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
 
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int cost = (k[i] + k[j]) * (abs(points[i].first - points[j].first) 
            + abs(points[i].second - points[j].second));
            adj[i].push_back({cost, j});
            adj[j].push_back({cost, i});
        }
    }
 
    vector <int> d(n + 1);
    for (int i = 1; i <= n; i++) {
        adj[0].push_back({c[i], i});
        adj[i].push_back({c[i], 0});
        d[i] = 2e9;
    }
 
    int ans = 0;
    d[0] = 0;
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
    pq.push({d[0], 0});
    vector <int> trace(n + 1, -1);
 
    while ((int) pq.size() > 0) {
        auto [du, u] = pq.top();
        pq.pop();
        if (du > d[u]) continue;
        ans += d[u];
        d[u] = -2e9;
        for (auto [c, v] : adj[u]) {
            if (d[v] > c) {
                d[v] = c;
                pq.push({d[v], v});
                trace[v] = u;
            }
        }
    }
 
    std :: cout << ans << '\n';
 
    vector <int> numPS = {};
    for (int i = 1; i <= n; i++) {
        if (trace[i] == 0) numPS.push_back(i);
    }
    std :: cout << numPS.size() << '\n';
    for (int x : numPS) std :: cout << x << ' ';
    std :: cout << '\n';
 
    vector <pair <int, int>> edge = {};
    for (int i = 1; i <= n; i++) {
        if (trace[i] > 0) {
            edge.push_back({i, trace[i]});
        }
    }
    std :: cout << edge.size() << '\n';
    for (auto [x, y] : edge) {
        cout << x << ' ' << y << '\n';
    }
 
    return 0;
}