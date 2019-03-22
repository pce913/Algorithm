#include<iostream>
using namespace std;
typedef long long ll;
ll b[4005], N[4005];
ll n;
ll gcd;
ll test;
ll GCD(ll x,ll y) {
    if (y == 0)return x;
    return GCD(y, x%y);
}
 
void Euclid(ll x,ll y,ll& a,ll& b) {
    if (x + y == 1) {
        a = x, b = y;
        return;
    }
    Euclid(y, x%y, b, a);
    b -= (x / y)*a;
    b %= x;
    a %= y;
}
 
void go(ll i) {
    if (i >= n - 1) {
        ll ans = b[i] % N[i];
        if (ans < 0)ans += N[i];
        cout << "#" << test << " " << ans << "\n";
        return;
    }
    ll s = 0, t = 1;
    Euclid(N[i], N[i + 1], s, t);
    gcd = GCD(N[i], N[i + 1]);
    ll sp = s * (b[i + 1] - b[i]) / gcd;
    ll np = N[i + 1] / gcd;
    N[i + 1] = N[i] * np;
    b[i + 1] = N[i] * sp + b[i];
    go(i + 1);
}
 
void solve() {
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> b[i] >> N[i];
    }
    go(0);
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    ll T;
    cin >> T;
    for (test = 1; test <= T; test++)solve();
    return 0;
}
