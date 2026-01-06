// 1791E
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<ll> v(n);

  for (auto &i : v)
    cin >> i;

  ll mn = 1e18, sum = 0, ng = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] < 0)
      ng++;
    sum += abs(v[i]);
    mn = min(mn, abs(v[i]));
  }

  if (ng % 2 == 0)
    cout << sum << '\n';
  else
    cout << sum - 2 * mn << '\n';
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
