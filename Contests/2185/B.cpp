#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  int mx = INT_MIN;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    mx = max(mx, t);
  }

  cout << mx * n << '\n';
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
