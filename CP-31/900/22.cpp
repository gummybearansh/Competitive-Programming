// 1582B
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  int zC = 0, oC = 0;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    if (tmp == 0)
      zC++;
    else if (tmp == 1)
      oC++;
  }

  // cout << zC << ' ' << oC << '\n';
  ll ans = oC;
  if (zC > 0) {
    ans = oC * (1LL << zC);
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
  return 0;
}
