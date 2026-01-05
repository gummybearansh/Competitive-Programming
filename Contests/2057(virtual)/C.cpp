#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  ll n, m;
  cin >> n >> m;
  n >= m ? cout << n + 1 << '\n' : cout << m + 1 << '\n';
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
