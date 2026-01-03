// 1826B
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

// see notes for indepth discussion and implementation using AxB tiling
// visualisation
ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

void solve() {
  int n;
  cin >> n;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  // very intersting implementation of euclid division algorithm
  // if v % x == u % x -> then |v - u| is a multiple of x
  // do that for the entire array, and find the gcd of all [V - U]
  ll ans = 0;
  int i = 0, j = n - 1;
  while (i <= j) {
    ans = gcd(ans, abs(v[i] - v[j]));
    i++;
    j--;
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
}
