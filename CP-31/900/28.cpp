// 1440B
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  int right = n - (n + 1) / 2;

  int tt = n * k;
  vector<ll> v(tt);
  for (auto &i : v)
    cin >> i;

  ll s = 0;
  int i = 1;
  while (k--) {
    s += v[tt - i * (right + 1)];
    i++;
  }

  cout << s << '\n';
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
