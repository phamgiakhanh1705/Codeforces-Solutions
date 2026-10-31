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
    
int n, x;
vector <int> d;
vector <int> a;
 
bool check(int k, int x) {
    vector <ll> vec = {};
    for (int i = 1; i <= n; i++)
        if (d[i] > k) vec.push_back(a[i]);
 
    vector <int> dp((int) vec.size() + 1, 0);
    for (int i = 1; i <= (int) vec.size(); i++) {
        dp[i] = dp[i - 1] + 1;
        if (i > 1) {
            if (vec[i - 1] - vec[i - 2] <= 2 * k)
            chmin(dp[i], dp[i - 2] + 1);
        }
    }
    return dp[(int) vec.size()] <= x;
}
 
void solve() {
    cin >> n >> x;
    
    d.resize(n + 1, 0); 
    a.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
 
    int l, r;
    for (int i = 1; i <= n; i++) {
        l = r = INT_MAX;
        if (i > 1) l = a[i] - a[i - 1];
        if (i < n) r = a[i + 1] - a[i];
        d[i] = min(l, r);
    }
 
    int left = 1, right = 2e9, ans = 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (check(mid, x)) {
            right = mid;
            ans = mid;
        }
        else {
            left = mid + 1;
        }
    }
    
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