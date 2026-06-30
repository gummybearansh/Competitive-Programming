// 489B
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> b(n);
  for (auto &i : b)
    cin >> i;

  int m;
  cin >> m;
  vector<int> g(m);
  for (auto &i : g)
    cin >> i;

  sort(b.begin(), b.end());
  sort(g.begin(), g.end());

  int i1 = 0, i2 = 0;
  int ans = 0;
  while (i1 < n && i2 < m) {
    if (abs(b[i1] - g[i2]) <= 1) {
      ans++;
      i1++;
      i2++;
    } else {
      // move the smaller one ahead
      b[i1] > g[i2] ? i2++ : i1++;
    }
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
