// 1715 B
#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

void solve() {
  ll n, k, b, s;
  cin >> n >> k >> b >> s;
  // greedy condition - if sum is too much or sum is too little
  if ((k * b + (k - 1) * n < s) || (k * b > s)) {
    cout << -1 << '\n';
    return;
  }

  // better less spaghetti code
  // distribute beauty directly
  s -= k * b;
  for (int i = 0; i < n; i++) {
    // greedily tkae min of k-1 or whatever's left
    ll add = min(s, k - 1);

    s -= add;

    // if we're on the first element - we add it to k * b - otherwise the elements just get add
    if (i == 0) {
      cout << k * b + add << ' ';
    } else {
      cout << add << ' ';
    }
  }
  cout << '\n';

  // // now make the array greedily
  // // satisfies beauty requirement
  // ll sum = k * b;
  // if (s - sum != 0) {
  //   sum += min(s - sum, k - 1);
  // }
  // cout << sum << ' ';
  // for (int i = 1; i < n; i++) {
  //   if (s - sum >= k - 1) {
  //     cout << k - 1 << ' ';
  //     sum += k - 1;
  //   } else {
  //     cout << s - sum << ' ';
  //     sum += s - sum;
  //   }
  // }
  // cout << '\n';
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
