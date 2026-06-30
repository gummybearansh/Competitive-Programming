#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<char>> v(n, vector<char>(4));

  for (auto &r : v) {
    for (auto &c : r) {
      cin >> c;
    }
  }
  // for (auto r : v) {
  //   for (auto c : r) {
  //     cout << c << ' ';
  //   }
  //   cout << '\n';
  // }

  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < 4; j++) {
      if (v[i][j] == '#') {
        cout << j + 1 << ' ';
        break;
      }
    }
  }
  cout << '\n';
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
