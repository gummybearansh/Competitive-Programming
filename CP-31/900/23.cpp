// 1559A
#include <bits/stdc++.h>

#define ll long long

using namespace std;

// if i want to minimise the maximum value:
// taking and of all elements will result in a value less than or equal to the smallest value of all elements 
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v) {
    cin >> i;
  }

  int ans = v[0];
  for (int i = 1; i < n; i++) {
    ans = (ans & v[i]);
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
