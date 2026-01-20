#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  int even = -1, odd = -1;
  int t;
  cin >> t;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  for (int i = 2; i < n - 2; i++) {
    if (abs(v[i - 2] - v[i]) == 1 || abs(v[i] - v[i + 2]) == 1) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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
