// 1704B
#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  // create a range for each v[i] -> valid segment of v[i]
  vector<pair<ll, ll>> segments(n);
  for (int i = 0; i < n; i++) {
    // valid range l -> r that v[i] can be consumed in
    segments[i] = {v[i] - x, v[i] + x};
  }

  // set initial range to be v[0]s range
  ll l = segments[0].first, r = segments[0].second;
  int changes = 0;
  // now we iterate over the remaining segements
  for (int i = 1; i < n; i++) {
    // new range is intersection of current range and this segment's range
    l = max(l, segments[i].first);
    r = min(r, segments[i].second);

    // if someone's range does not fit in the current range
    if (l > r) {
      // update the range to be this segment and increment changes
      l = segments[i].first;
      r = segments[i].second;
      changes++;
    }
  }

  cout << changes << '\n';
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
