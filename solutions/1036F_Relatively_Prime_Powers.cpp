#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const ll MAX_N = 1000000000000000000LL; 
 
ll int_sqrt(ll n) {
    if (n <= 1) return n;
    ll x = sqrtl(n);
    while (x * x > n) --x;
    while ((x + 1) * (x + 1) <= n) ++x;
    return x;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    vector<ll> powers;
    for (int b = 3; b <= 60; ++b) {
        for (ll a = 2; ; ++a) {
            ll val = 1;
            bool overflow = false;
            for (int i = 0; i < b; ++i) {
                if (val > MAX_N / a) {
                    overflow = true;
                    break;
                }
                val *= a;
            }
            if (overflow) break;
            powers.push_back(val);
        }
    }
 
    sort(powers.begin(), powers.end());
    powers.erase(unique(powers.begin(), powers.end()), powers.end());
 
    vector<ll> nonsq;
    for (ll x : powers) {
        ll s = int_sqrt(x);
        if (s * s != x) {
            nonsq.push_back(x);
        }
    }
 
    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
 
        ll s = int_sqrt(n);
        ll squares = (s >= 2) ? s - 1 : 0;               
        ll higher = upper_bound(nonsq.begin(), nonsq.end(), n) - nonsq.begin(); 
 
        ll perfect = squares + higher;                  
        ll elegant = (n - 1) - perfect;                 
 
        cout << elegant << '\n';
    }
    return 0;
}