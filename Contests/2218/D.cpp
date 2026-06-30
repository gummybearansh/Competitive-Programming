#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast                   \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);

vector<ll> primes;

void sieve(int lim) {
  vector<bool> is_prime(lim + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= lim; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= lim; j += i) {
        is_prime[j] = false;
      }
    }
  }
  for (int i = 2; i <= lim; i++) {
    if (is_prime[i])
      primes.push_back(i);
  }
}

void solve() {
  int n;
  cin >> n;

  vector<ll> a(n);

  a[0] = primes[0];
  for (int i = 1; i < n - 1; i++) {
    a[i] = primes[i - 1] * primes[i];
  }
  a[n - 1] = primes[n - 2];

  for (int i = 0; i < n; i++) {
    cout << a[i] << " \n"[i == n - 1];
  }
}

int main() {
  fast;

  // Need at most around 1e4 primes total
  sieve(200000);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
