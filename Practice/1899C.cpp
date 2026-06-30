#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<ll> v(n);
  for (auto &i : v)
    cin >> i;

  ll max_sum = v[0], curr_sum = v[0];
  for (int i = 1; i < n; i++) {
    // alternating parity check
    if (abs(v[i]) % 2 != abs(v[i - 1]) % 2) {
      // kadane check
      curr_sum = max(v[i], v[i] + curr_sum);
    } else {
      // same parity - forced reset - start herre
      curr_sum = v[i];
    }
    max_sum = max(curr_sum, max_sum);
  }

  cout << max_sum << '\n';
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
