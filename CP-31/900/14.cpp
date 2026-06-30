// 1679A
#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

void solve() {
  ll n;
  cin >> n;
  // minimum 4 wheels
  // 4 or 6 wheels - n needs to be even
  if (n < 4 || n % 2 != 0) {
    cout << -1 << '\n';
    return;
  }

  n /= 2;

  cout << (n + 2) / 3 << ' ' << n / 2 << '\n';
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
