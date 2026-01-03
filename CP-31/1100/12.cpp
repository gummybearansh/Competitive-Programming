// 1827A
#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());

  int a_idx = 0;
  ll possibilities = 1;
  ll mod = 1e9 + 7;

  for (int b_idx = 0; b_idx < n; b_idx++) {
    // cout << possibilities << '\n';
    while (a_idx < n && a[a_idx] > b[b_idx]) {
      a_idx++;
    }
    // cout << a_idx << ' ' << b_idx << '\n';

    ll count = a_idx - b_idx;
    if (count <= 0) {
      cout << 0 << '\n';
      return;
    }

    // need mod
    possibilities = (possibilities * count) % mod;
  }

  cout << possibilities << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
