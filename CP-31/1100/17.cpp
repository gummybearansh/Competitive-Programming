// 1797B

#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  // size, default value (empty vector of size n)
  vector<vector<int>> v(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> v[i][j];
    }
  }

  // can just iterate over whole grid
  int min_ops = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (v[i][j] != v[n - 1 - i][n - 1 - j])
        min_ops++;
    }
  }
  min_ops /= 2;

  if (min_ops > k) {
    cout << "NO\n";
    return;
  }

  // but need to do EXACTLY K OPS, NOT MIN
  if (n % 2 == 1) {
    // always possible with odd, flip the center bit as many times
    cout << "YES\n";
    return;
  }

  // but if u have even grid -> if extra flips is odd -> will fuck up
  if ((min_ops - k) % 2 == 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

  // int ops = 0;
  // for (int i = 0; i <= n / 2; i++) {
  //   if (n % 2 == 0 && i == (n / 2)) {
  //     break;
  //   }
  //   for (int j = 0; j < n; j++) {
  //     // cout << i << j << ' ' << n - 1 - i << n - 1 - j << '\n';
  //     if (n % 2 == 1 && i == n / 2 && j == n / 2) {
  //       break;
  //     }
  //     if (v[i][j] != v[n - 1 - i][n - 1 - j])
  //       ops++;
  //     if (ops > k) {
  //       cout << "NO\n";
  //       return;
  //     }
  //   }
  // }
  // cout << "YES\n";
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
