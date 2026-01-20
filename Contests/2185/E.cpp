// very very beautiful problem
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  // set is sorted, so spikes are automatically stored sorted
  set<int> b;
  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    b.insert(t);
  }

  string s;
  cin >> s;

  // storing distance to spike in before and after sets because they are sorted,
  // so automatically the ones dying first will be first
  set<pair<int, int>> before, after;
  // vector to help us delete from both sets faster - will store before and
  // after of each robot
  vector<pair<int, int>> bef_aft;
  for (int i = 0; i < n; i++) {
    // first spike that's bigger than position of current robot
    auto it = b.upper_bound(v[i]);
    int bef = INT_MAX, aft = INT_MAX;

    // aft stores how many steps can it take to the right, default values
    // INT_MAX
    if (it != b.end())
      aft = (*it) - v[i];
    // bef stores how many steps it can take to the left
    // it-- because it is currently pointing to spike just to the right.
    if (it != b.begin()) {
      it--;
      bef = v[i] - (*it);
    }

    before.insert({bef, i});
    after.insert({aft, i});
    bef_aft.push_back({bef, aft});
  }

  int pos = 0, ans = n;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'L')
      pos--;
    else
      pos++;

    if (pos > 0) {
      while (!after.empty() && abs(pos) >= (*after.begin()).first) {
        auto i = (*after.begin()).second;
        after.erase(after.begin());
        before.erase((before.find({bef_aft[i].first, i})));
        ans--;
      }
    } else {
      while (!before.empty() && abs(pos) >= (*before.begin()).first) {
        auto i = (*before.begin()).second;
        before.erase(before.begin());
        after.erase(after.find({bef_aft[i].second, i}));
        ans--;
      }
    }
    cout << ans << ' ';
  }
  cout << '\n';
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
