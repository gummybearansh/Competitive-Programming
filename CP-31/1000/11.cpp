// 1725B
#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

void solve() {
  int n, d;
  cin >> n >> d;

  vector<int> v(n);
  for (auto &i : v) {
    cin >> i;
  }

  sort(v.rbegin(), v.rend());
  // how many times strongest player needed to beat oppopnent team?
  // treat every other player as the same and we only care about the strong players
  int consumed_players = 0;
  // for each strongest player - try to make a team
  int ans = 0;
  for (int i = 0; i < n; i++) {
    // no -1 because we want it to be strictly greater
    int num = (d + v[i]) / v[i];

    if (consumed_players + num <= n) {
      ans++;
      consumed_players += num;
    } else {
      // not enough players
      break;
    }
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
