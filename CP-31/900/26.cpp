// 1475A
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  ll n;
  cin >> n;

  // Observation: A number is made up of prime factors.
  // all prime factors other than 2 are odd
  // so if a number is made up of exclusively 2 as prime factor -> 2^k, then it
  // has no odd factors other than that every number has odd divisor beautiful
  // way to check if a number is just 2^k n = 2^k => (n)2 = 100000... n-1
  // =>(n-1)2 = 011111... n & (n-1) => 0000 so if n & n-1 = 0 => then the number
  // is exclusively 2^something. otherwise it's made up of odd divisor

  if ((n & (n - 1)) == 0)
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
