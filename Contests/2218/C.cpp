#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast                   \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cout << i + 1 << ' ' << (n + 1 + 2 * i) << ' ' << (n + 2 + 2 * i) << ' ';
  }
  cout << '\n';
}

int main() {
  fast

      int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
