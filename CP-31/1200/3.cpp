#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll sumTill(ll x) { return (x * (x + 1)) / 2; }

void solve() {
  ll n, x, y;
  cin >> n >> x >> y;

  // multiples of x in n:
  ll plus = n / x;
  // multiples of y in n:
  ll minus = n / y;

  // remove lcm of x and y from both
  // LCM of (x,y) = x*y / gcd(x,y)
  ll remove = (x / gcd(x, y)) * y;
  remove = n / remove;

  plus -= remove;
  minus -= remove;

  // minus will have from 1 - minus
  minus = sumTill(minus);

  // plus will have:
  plus = sumTill(n) - sumTill(n - plus);

  cout << plus - minus << '\n';
}

// n ~ 1e9
// gives tle
void solveTLE() {
  ll n, x, y;
  cin >> n >> x >> y;

  ll big = n, small = 1, ans = 0;
  // need largest numbers for x
  // need smallest numbers for y
  for (int i = 0; i < n; i++) {
    if ((i + 1) % x == 0) {
      if ((i + 1) % y == 0)
        continue;
      ans += big;
      big--;
    } else if ((i + 1) % y == 0) {
      ans -= small;
      small++;
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
