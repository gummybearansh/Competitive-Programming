// 1800B
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  // map -> capital and small letters
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  // {a, {2, 3}} -> freq of lowercase, upperCase
  map<char, pair<int, int>> mpp;
  for (char c : s) {
    islower(c) ? mpp[c].first++ : mpp[tolower(c)].second++;
  }

  int ans = 0;
  for (auto ch : mpp) {
    ans += min(ch.second.first, ch.second.second);
    // difference / 2 k needed
    if (k > 0) {
      ans += abs(ch.second.first - ch.second.second) / 2;
      k -= abs(ch.second.first - ch.second.second) / 2;
      if (k < 0) {
        ans += k;
        k = 0;
      }
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
