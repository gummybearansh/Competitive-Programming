#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<string> v(n);
  for (auto &i : v)
    cin >> i;

  int ops = 0;

  // i goes till (n + 1) / 2 to catch top half of middle row(if odd)
  // j goes till n / 2 to avoid double counting
  for (int i = 0; i < (n + 1) / 2; i++) {
    for (int j = 0; j < n / 2; j++) {
      // 90 degree rotatoinal mapping
      char a = v[i][j];
      char b = v[j][n - 1 - i];
      char c = v[n - 1 - i][n - 1 - j];
      char d = v[n - 1 - j][i];

      int o = 0, z = 0;
      a == '1' ? o++ : z++;
      b == '1' ? o++ : z++;
      c == '1' ? o++ : z++;
      d == '1' ? o++ : z++;

      ops += min(o, z);
    }
  }

  cout << ops << '\n';
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
