// 1669F
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  int l = 0, r = n - 1, ans = 0;
  ll ls = 0, rs = 0;

  while (l <= r) {
    if (ls == rs) {
      ans = max(ans, l + n - 1 - r);
    }

    // ans recorded, now next
    if (ls <= rs) {
      ls += v[l];
      l++;
    } else {
      rs += v[r];
      r--;
    }
  }
  if (ls == rs)
    ans = max(ans, l + n - 1 - r);
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
