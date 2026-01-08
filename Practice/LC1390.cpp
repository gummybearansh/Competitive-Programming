#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &it : v)
    cin >> it;

  // sum of divisors in v such that it has exactly 4 divisors
  int sum = 0, sumC = 0;
  // optimised 
  for (int i = 0; i < n; i++) {
    int divisors = 0, sumC = 0;
    // cout << v[i] << '\n';
    for (int j = 2; j < v[i]; j++) {
      // cout << divisors << ' ' << sumC << '\n';
      if (v[i] % j == 0) {
        divisors++;
        sumC += j;
        if (divisors > 2)
          break;
      }
    }
    if (divisors == 2) {
      sum += (1 + v[i] + sumC);
    }
  }
  cout << sum << '\n';
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
