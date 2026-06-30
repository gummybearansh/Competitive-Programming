#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

void solve() {
  ll a, b;
  cin >> a >> b;

  if (a == 1) {
    cout << b * b << '\n';
    return;
  } else if (b == 1) {
    cout << a * a << '\n';
    return;
  }

  ll ans = (a * b) / gcd(a, b);
  if (ans <= max(a, b))
    cout << ans * max(a, b) / min(a, b) << '\n';
  else
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
