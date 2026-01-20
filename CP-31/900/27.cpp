// 1471A
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  ll n, x;
  cin >> n >> x;
  ll minS = 0, max = 0;

  for (int i = 0; i < n; i++) {
    ll tmp;
    cin >> tmp;
    minS += tmp;
    max += (tmp + x - 1) / x;
  }

  cout << (minS + x - 1) / x << ' ' << max << '\n';
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
