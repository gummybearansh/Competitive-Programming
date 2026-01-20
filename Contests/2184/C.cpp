#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  ll n, k;
  cin >> n >> k;

  if (k == n) {
    cout << 0 << '\n';
  }

  if (n < k) {
    cout << -1 << '\n';
  }

  for (int i = 1; i < 40; i++) {
    ll piles = 1LL << i;

    int val = n / piles;
    ll r = n % piles;

    bool found = false;

    // big
    if (r > 0 && (val + 1) == k) {
      cout << i << '\n';
      return;
    }

    // small
    if ((piles - r) > 0 && val == k) {
      cout << i << '\n';
      return;
    }

    if (val < k)
      break;
  }

  cout << -1 << '\n';

  // bool flag = false;
  // if (k == 1)
  //   flag = true;
  //
  // if (n == k) {
  //   cout << 0 << '\n';
  // }
  //
  // ll ops = 0;
  // while (k <= n) {
  //   ops++;
  //   k *= 2;
  // }
  //
  // if (k - n <= ops) {
  //   cout << ops << '\n';
  //   return;
  // }
  //
  // k /= 2, ops -= 1;
  // // cout << k << ' ' << ops << '\n';
  // //
  // if (flag) {
  //   cout << ops << '\n';
  //   return;
  // }
  //
  // if (n - k <= ops) {
  //   cout << ops << '\n';
  // } else
  //   cout << -1 << '\n';

  // ll ops = n / k;
  //
  // ops--;
  // ll num = k * (1 << (ops));
  //
  // if (num - n <= ops)
  //   cout << ops << '\n';
  // else
  //   cout << -1 << '\n';
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
