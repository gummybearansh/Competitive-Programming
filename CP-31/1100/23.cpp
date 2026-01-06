// 1708B
#include <bits/stdc++.h>

#define ll long long

using namespace std;

// observation -> gcd(1, a1), gcd(1, a2) ... gcd(n, an) needs to be unique and
// gcd(i, ai) <= i so to make it unique - we just need the gcd of (i, ai) = i
// gcd(1, a1) <= 1, gcd(2, a2) <= 2, gcd(3, a3) <= 3, gcd(4, a4) <= 4 ... so
// since gcd(i, ai) <= i and true for all values before current, then gc(i, ai)
// == i for all to be unique so ai should be a multiple of i find smallest l >=
// ai >= r that is a multiple of i
// smallest value that is greater than l but is a multiple of i = ceil(l / i) *
// i -------
void solve() {
  ll n, r, l;
  vector<ll> ans;
  cin >> n >> l >> r;
  for (int i = 1; i <= n; i++) {
    ll tmp = i;
    // need smallest multiple of i > l < r
    tmp = ((l + i - 1) / i) * i;
    if (tmp <= r)
      ans.push_back(tmp);
    else {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  for (auto it : ans)
    cout << it << ' ';
  cout << '\n';
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
