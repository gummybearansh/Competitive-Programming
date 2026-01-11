// 1593B
#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll minOps(string s, string end_value) {
  int idx = 1;
  int n = s.size() - 1;
  ll ops = 0;
  for (int i = n; i > -1; i--) {
    if (s[i] == end_value[idx]) {
      idx--;
      if (idx < 0)
        break;
    } else
      ops++;
  }
  if (idx < 0)
    return ops;
  return LLONG_MAX;
}

void solve() {
  string s;
  cin >> s;

  vector<string> possible_values = {"75", "00", "50", "25", "50"};

  ll ans = LLONG_MAX;
  for (int i = 0; i < possible_values.size(); i++) {
    ans = min(ans, minOps(s, possible_values[i]));
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
