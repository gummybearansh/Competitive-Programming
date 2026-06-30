#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<ll> v(n);
  for (auto &i : v) {
    cin >> i;
  }

  sort(v.begin(), v.end(), greater<>());

  ll a = 0, b = 0;
  for (int i = 0; i < n; i++) {
    // alice takes even index (starts first)
    if (i % 2 == 0) {
      // only eats positives
      if (v[i] % 2 == 0)
        a += v[i];
    } else {
      // bob only eats negatives
      if (v[i] % 2 == 1)
        b += v[i];
    }
  }
  if (a > b)
    cout << "Alice\n";
  else if (b > a)
    cout << "Bob\n";
  else
    cout << "Tie\n";
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
