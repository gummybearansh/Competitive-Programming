// 1607B
#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

void solve() {
  ll x, n;
  cin >> x >> n;

  bool even;
  x % 2 == 0 ? even = true : even = false;

  if (n % 4 == 0) {
    cout << x << '\n';
  } else if (n % 4 == 1) {
    if (even) {
      cout << x - n << '\n';
    } else {
      cout << x + n << '\n';
    }
  } else if (n % 4 == 2) {
    if (even) {
      cout << x + 1 << '\n';
    } else {
      cout << x - 1 << '\n';
    }
  } else {
    if (even) {
      cout << x + (n + 1) << '\n';
    } else {
      cout << x - (n + 1) << '\n';
    }
  }
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
