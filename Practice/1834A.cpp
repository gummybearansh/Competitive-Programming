#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;

  int ng = 0, pv = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    if (num < 0)
      ng++;
    else
      pv++;
  }

  if (ng > pv) {
    int dif = (ng - pv);
    ng -= (dif + 1) / 2;
    pv += (dif + 1) / 2;
    ans += (dif + 1) / 2;
  }

  if (ng % 2 == 1)
    ans += 1;
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
  return 0;
}
