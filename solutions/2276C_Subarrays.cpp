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
 
    vector <int> pref(n + 1, 0);
    vector <ll> freq(k, 0);
    freq[0] = 1; 
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        pref[i] = (pref[i - 1] + x) % k;
        freq[pref[i]]++;
    }
 
    ll ans = 0;
    for (ll f : freq) {
        ans += f * (f - 1) / 2;
    }
 
    vector <int> cnt(k, 0);
    cnt[pref[0]] = 1;
    for (int r = 1; r <= n; ++r) {
        if (r > k) {
            cnt[pref[r - k - 1]]--;
        }
        ans -= cnt[pref[r]];
        ++cnt[pref[r]];
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