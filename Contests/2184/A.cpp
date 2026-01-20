#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  if (n == 2)
    cout << 2 << '\n';
  else if (n == 3)
    cout << 3 << '\n';
  else if (n % 2 == 0)
    cout << 0 << '\n';
  else
    cout << 1 << '\n';
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
