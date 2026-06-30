// 1543A
#include <bits/stdc++.h>

#define ll long long

using namespace std;

// beautiful
void solve() {
  ll a, b;
  cin >> a >> b;

  if (a == b) {
    cout << 0 << ' ' << 0 << "\n";
    return;
  }

  // the max GCD: a - b
  ll x = abs(a - b);

  cout << x << ' ' << min(a % x, x - a % x) << '\n';
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
