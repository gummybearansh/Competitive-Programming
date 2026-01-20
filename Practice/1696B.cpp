#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  // find first non-zero index
  int first = -1;
  for (int i = 0; i < n; i++) {
    if (v[i] != 0) {
      first = i;
      break;
    }
  }
  if (first == -1) {
    // all are zeroes
    cout << 0 << '\n';
    return;
  }

  // find last non-zero index
  int last = -1;
  for (int i = n - 1; i >= 0; i--) {
    if (v[i] != 0) {
      last = i;
      break;
    }
  }

  // check the middle, if it has 0 -> ans = 2, otherwise ans = 1 (can wipe out
  // entire with 1 mex, or have to do mex twice to make them all 0)
  for (int i = first; i <= last; i++) {
    if (v[i] == 0) {
      cout << 2 << '\n';
      return;
    }
  }
  cout << 1 << '\n';
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
