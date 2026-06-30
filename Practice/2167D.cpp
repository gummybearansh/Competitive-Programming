// 2167D
#include <bits/stdc++.h>

#define ll long long

using namespace std;

vector<int> seive(int n) {
  vector<bool> isPrime(n + 1, 1);
  isPrime[0] = 0;
  isPrime[1] = 0;
  for (int i = 2; i * i <= n; i++) {
    if (isPrime[i]) {
      for (int p = i * i; p <= n; p += i) {
        isPrime[p] = false;
      }
    }
  }

  vector<int> primes;
  for (int i = 0; i < isPrime.size(); i++) {
    if (isPrime[i])
      primes.push_back(i);
  }
  return primes;
}

void solve(vector<int> &primes) {
  // smallest prime number that does not divide them all
  int n;
  cin >> n;
  vector<ll> v(n);
  for (auto &i : v)
    cin >> i;

  for (int primeIdx = 0; primeIdx < primes.size(); primeIdx++) {
    for (int i = 0; i < n; i++) {
      if (v[i] % primes[primeIdx] != 0) {
        cout << primes[primeIdx] << '\n';
        return;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  vector<int> primes = seive(100);
  while (t--) {
    solve(primes);
  }
  return 0;
}
