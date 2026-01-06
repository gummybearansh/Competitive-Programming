// 1791G1
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  ll n, c;
  cin >> n >> c;

  vector<ll> v(n);
  for (auto &i : v)
    cin >> i;

  for (int i = 0; i < n; i++) {
    v[i] += (i + 1);
  }

  // now i have cost for using each tp from 0, try to max out as many tp as u
  // can use
  sort(v.begin(), v.end());

  ll tp = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] <= c) {
      c -= v[i];
      tp++;
    } else
      break;
  }

  cout << tp << '\n';
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
