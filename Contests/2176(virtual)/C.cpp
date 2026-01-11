#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<ll> odds, evens;
  for (int i = 0; i < n; i++) {
    ll tmp;
    cin >> tmp;
    tmp % 2 == 1 ? odds.push_back(tmp) : evens.push_back(tmp);
  }

  sort(odds.rbegin(), odds.rend());
  sort(evens.rbegin(), evens.rend());

  int n_odds = odds.size();
  int n_evens = evens.size();

  vector<ll> pf_e(n_evens + 1, 0);
  for (int i = 0; i < n_evens; i++)
    pf_e[i + 1] = pf_e[i] + evens[i];

  // count of number of even and odd coins u have taken
  ll cnt_o = 0, cnt_e = 0;
  for (int k = 1; k <= n; k++) {
    if (n_odds == 0) {
      cout << 0 << ' ';
      continue;
    }

    ll score = odds[0];
    int slots_left = k - 1;

    int take_evens = min(n_evens, slots_left);

    int take_odds_trash = slots_left - take_evens;

    if (take_odds_trash % 2 == 1) {
      // we need to swap even for odd
      take_evens--;
      take_odds_trash++;
    }

    if (take_evens < 0 || take_odds_trash > n_odds - 1) {
      cout << 0 << ' ';
    } else {
      cout << score + pf_e[take_evens] << ' ';
    }
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
