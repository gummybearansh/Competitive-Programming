#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  } 

  sort(v.rbegin(), v.rend());
  sort(v.begin(), v.end(), greater<int>()); // #include <functional>

  vector<int> evens, odds;

  for (int i = 0; i < n; i++) {
    if (v[i] % 2 == 0)
      evens.push_back(v[i]);
    else
      odds.push_back(v[i]);
  }

  if (evens.size() == 0) {
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        cout << odds[0] << ' ';
      } else
        cout << 0 << ' ';
    }
    cout << '\n';
    return;
  }

  if (odds.size() == 0) {
    for (int i = 0; i < n; i++) {
      cout << 0 << ' ';
    }
    cout << '\n';
    return;
  }

  ll sum = 0;
  int ev_idx = 0;
  bool dec = false;
  for (int i = 1; i <= n; i++) {
    // i operations karne hai
    if (dec) {
      if (evens.size() > 1) {
        cout << sum - evens.back() << ' ';
        dec = false;
        ev_idx++;
        continue;
      } else {
        cout << 0 << ' ';
        dec = false;
        ev_idx++;
        continue;
      }
    }
    if (i == 1) {
      sum = odds[0];
    } else {
      // cout << "hello\n" << '\n';
      if (ev_idx < evens.size()) {
        sum += evens[ev_idx];
        ev_idx++;
      }
      // cout << ev_idx << '\n';
      if (ev_idx >= evens.size()) {
        dec = true;
      }
    }

    cout << sum << ' ';
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
