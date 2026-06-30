// 1703E
#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> v(n, vector<int>(n));

  int z = 0, o = 0;
  for (auto &r : v) {
    for (auto &c : r) {
      cin >> c;
      c == 0 ? z++ : o++;
    }
  }

  // either make them all 0s, or all 1s, or that middle cross
  // or opposite of middle cross
  int plus = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == n / 2 || j == n / 2) {
        if (v[i][j] == 0) {
          plus++;
        }
      } else if (n % 2 == 0 && (i == n / 2 - 1 || j == n / 2 - 1)) {
        if (v[i][j] == 0) {
          plus++;
        }
      } else if (v[i][j] == 1)
        plus++;
    }
  }
  plus = min(plus, n * n - plus);
  z = min(z, o);

  cout << min(z, plus) << '\n';
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
