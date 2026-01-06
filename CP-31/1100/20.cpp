// 1780B
// if u can break the array down into N chunks with GCD = x, then it's optimal
// to break it down to 2 chunks here's how: say N = 3 -> xA , xB , xC are the
// sum of the three chunks, combining them down to 2 chunks: x(A + B) , xC ->
// will hhave GCD of atleast x therefore it is optimal to break it down to 2
// groups - calculate sum at each split, and find maxGCD
#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

void solve() {
  int n;
  cin >> n;
  vector<ll> v(n);
  for (auto &i : v)
    cin >> i;

  vector<ll> pf(n);
  pf[0] = v[0];

  for (int i = 1; i < n; i++) {
    pf[i] = pf[i - 1] + v[i];
  }

  ll maxSum = pf[n - 1], mxGCD = 0;
  // have to leave atleast 1 element in the second chunk (k > 1)
  for (int i = 0; i < n - 1; i++) {
    ll a = pf[i];
    ll b = maxSum - a;
    mxGCD = max(mxGCD, gcd(a, b));
  }

  cout << mxGCD << '\n';
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
