#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  if ((n > 2 && m >= 2)|| (m > 2 && n >= 2)) cout << "YES\n";
  else cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
