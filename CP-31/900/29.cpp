// 1380A
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  for (int i = 1; i < n - 1; i++) {
    if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
      cout << "YES\n";
      cout << i << ' ' << i + 1 << ' ' << i + 2 << '\n';
      return;
    }
  }

  cout << "NO\n";
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
