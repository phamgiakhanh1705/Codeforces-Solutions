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
 
void add(int l, int r, ll a, ll b, vector <ll> &diff_a, vector <ll> &diff_b) {
    if (l > r) return;
 
    diff_a[l] += a;
    diff_a[r + 1] -= a;
 
    diff_b[l] += b;
    diff_b[r + 1] -= b;
}
 
void find_end(int l, const string &pattern, const vector <vector <int>> &pos, int n, int &result) {
    int cur = l - 1;
    for (char c : pattern) {
        int digit = c - '0';
        int left = 0;
        int right = sz(pos[digit]) - 1;
        int index = -1;
 
        while (left <= right) {
            int mid = left + (right - left) / 2;
 
            if (pos[digit][mid] > cur) {
                index = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
 
        if (index == -1) {
            result = n + 1;
            return;
        }
 
        cur = pos[digit][index];
    }
 
    result = cur;
}
 
void solve() {
    int n;
    string s;
    cin >> n >> s;
 
    vector <vector <int>> pos(11);
    for (int i = 1; i <= n; i++) {
        pos[s[i - 1] - '0'].push_back(i);
    }
 
    vector<ll> diff_a(n + 3, 0), diff_b(n + 3, 0);
    for (int l = 1; l <= n; l++) {
        int p, q;
        find_end(l, "2025", pos, n, p);
        find_end(l, "2026", pos, n, q);
 
        if (p >= q) continue;
 
        add(l, p, 0, q - p, diff_a, diff_b);
        add(p + 1, q - 1, -1, q, diff_a, diff_b);
    }
 
    ll a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        a += diff_a[i];
        b += diff_b[i];
 
        ll bad = a * i + b;
        ll total = 1ll * i * (n - i + 1);
 
        cout << total - bad << ' ';
    }
 
    cout << '\n';
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