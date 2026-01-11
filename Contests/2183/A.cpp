#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<ll> v(n);
  for (auto &i : v)
    cin >> i;

  if (v[0] == 1 || v[n - 1] == 1)
    cout << "Alice\n";
  else
    cout << "Bob\n";
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
