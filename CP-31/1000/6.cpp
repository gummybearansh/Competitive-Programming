// 1840C
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  ll n, k, q;
  cin >> n >> k >> q;

  vector<ll> v(n);
  for (ll &i : v)
    cin >> i;

  ll ans = 0, len = 0;

  for (int i = 0; i < n; i++) {
    if (v[i] <= q) {
      len++;
    } else {
      if (len >= k) {
        ll x = len - k + 1;
        ans += (x * (x + 1)) / 2;
      }
      len = 0;
    }
  }
  // need to do the check again (incase array ends with a valid day) then else
  // won't be executed
  if (len >= k) {
    ll x = len - k + 1;
    ans += (x * (x + 1)) / 2;
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
