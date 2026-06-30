#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (s[i] - s[i - 1] == 2) {
      ans++;
    }
  }
  cout << ans << '\n';
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
