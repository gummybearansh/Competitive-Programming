// 1731B
#include <bits/stdc++.h>

#define ll long long

using namespace std;

// n is 10^9
// cant do the O(n) solution, need O(1)
// observation = (1, 1) -> 1^2, (1, 2) -> 1*2, (2, 2) -> 2^2, (3,2) -> (3*2),
// (3,3) -> 3^2 for all i = 1-> n : we add square of i and i*(i-1) (even fits
// for i = 1) sum -> i^2 + i^2 - i = 2i^2 - i summation, see formulas ->
// n(n+1)/2 and n(n+1)(2n+1)/6 and simplify

void solve() {
  ll n;
  cin >> n;

  ll MOD = 1e9 + 7;
  ll t1 = n % MOD;
  ll t2 = (n + 1) % MOD;
  ll t3 = (4 * n - 1) % MOD;

  ll ans = t1;
  ans = (ans * t2) % MOD;
  ans = (ans * t3) % MOD;
  ans = (ans * 337) % MOD; // 2022 / 6

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
