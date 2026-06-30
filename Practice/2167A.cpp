#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a != b || b != c || c != d)
    cout << "NO\n";
  else
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
