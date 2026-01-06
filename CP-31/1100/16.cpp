// 1807G2
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<ll> v(n);
  for (auto &i : v)
    cin >> i;

  sort(v.begin(), v.end());

  if (v[0] != 1) {
    cout << "NO\n";
    return;
  }

  vector<ll> pf(n + 1, 0);

  for (int i = 0; i < n; i++) {
    pf[i + 1] = pf[i] + v[i];
  }

  for (int i = 1; i < n; i++) {
    if (v[i] > pf[i]) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
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
