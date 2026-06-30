// 1704C
#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> v(m);
  for (auto &i : v)
    cin >> i;

  // i actually need to greedily save the houses which have the biggest gaps
  // that will give me the best answer
  sort(v.begin(), v.end());
  vector<int> gaps;
  for (int i = 0; i < m; i++) {
    if (i == m - 1) {
      gaps.push_back(n - v.back() + v[0] - 1);
    } else {
      gaps.push_back(v[i + 1] - v[i] - 1);
    }
  }

  sort(gaps.rbegin(), gaps.rend());
  // for (auto i : gaps) {
  //   cout << i << ' ';
  // }
  // cout << '\n';

  // m are already infected, i'll add the ones that happen as they happen
  int ans = m, moves = 0;
  for (int i = 0; i < gaps.size(); i++) {
    // this is the biggest gap yet, so i can save the most houses here
    // how? i do just 2 moves and save all but 1 and then i move on
    // this gap will just eat the
    int spaceLeft = gaps[i] - 2 * moves;
    if (spaceLeft > 0) {
      // how many can i save in this gap?
      ans += 2 * moves;
      if (spaceLeft > 2) {
        moves += 2;
        // i'll safe the house right next to one, and then in the next turn right next to the one that just got infected - so only one more house will be infected
        ans += 1;
      } else if (spaceLeft == 1) {
        moves += 1;
        // only one ka gap, i'll save it
      } else if (spaceLeft == 2) {
        ans += 1;
        moves += 1;
      }
    } else
      ans += gaps[i];
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
