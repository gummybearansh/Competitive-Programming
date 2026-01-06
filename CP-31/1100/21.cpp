// 1742D
#include <bits/stdc++.h>

#define ll long long

using namespace std;

// play on constraints -> a -> atmost 1000
// store highest index of numbers in max_pos array
// loop over all co primes <1000 (1000 * 1000) if they exist in the array, find
// if they're co prime, if they are, blah lblah
void solve() {
  ll n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  // max position of every number from 1 - 1000
  vector<ll> max_pos(1001, -1);
  for (int i = 0; i < n; i++) {
    max_pos[v[i]] = i;
  }

  ll ans = -1;
  for (int i = 1; i < 1001; i++) {
    for (int j = 1; j < 1001; j++) {
      if (max_pos[i] != -1 && max_pos[j] != -1) {
        // if they both exist in the array, find if they're co prime
        if (gcd(i, j) == 1) {
          ans = max(ans, (max_pos[i] + max_pos[j] + 2));
        }
      }
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
