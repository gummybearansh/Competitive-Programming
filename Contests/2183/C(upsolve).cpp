#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  ll n, m, k;
  cin >> n >> m >> k;

  k--;
  // bs on answer in range [1, n]
  ll low = 1, high = n, ans = LLONG_MAX;
  while (low <= high) {
    ll mid = low + (high - low) / 2;

    // if i can fill 'mid' number of bases in <= m days
    ll days = LLONG_MAX;
    for (ll l = 0, r = mid - 1; r < n; l++, r++) {
      if (k < l || k > r)
        continue;

      ll left = k - l;
      ll right = r - k;
      days = min(days, left + right - 1 + max(left, right));
    }

    // days = minimum days it will take if im filling 'mid' number of bases
    if (days <= m) {
      low = mid + 1;
      ans = mid;
    } else {
      high = mid - 1;
    }
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
