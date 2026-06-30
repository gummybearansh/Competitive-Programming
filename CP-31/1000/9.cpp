// 1765M
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  int ans_a = 1;
  for (int i = 2; i * i <= n; i++) {
    // smallest factor
    if (n % i == 0) {
      // largest factor
      ans_a = n / i;
      break;
    }
  }

  int ans_b = n - ans_a;
  cout << ans_a << ' ' << ans_b << '\n';
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
