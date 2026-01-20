// 1857C
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<ll> v((n * (n - 1)) / 2);

  for (auto &i : v)
    cin >> i;

  // redundant logic, loop checks this
  // if (n == 2) {
  //   cout << v[0] << ' ' << v[0] << '\n';
  //   return;
  // }

  sort(v.begin(), v.end());
  // basically first n-1 elements is the first, then n-2 is the second...
  int i = 0, k = 1;
  while (i < (n * (n - 1)) / 2) {
    cout << v[i] << ' ';
    i += (n - k);
    k++;
  }

  cout << v.back() << '\n';
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
