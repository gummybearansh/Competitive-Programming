#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  bool flag = false;
  int days = 0, ones = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] == 0) {
      flag = false;
      days = max(days, ones);
      ones = 0;
    } else if (v[i] == 1) {
      ones++;
      if (flag)
        days = max(ones, days);
    } else if (v[i] == 2) {
      flag = true;
      days = max(days, ones);
    }
  }

  cout << days << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
