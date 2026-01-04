#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solveOptimal() {
  // need just the maximum consecutive zeores in cyclic duplicate string
  int n;
  cin >> n;
  string s;
  cin >> s;

  s += s;
  int z = 0, ans = 0;
  for (int i = 0; i < 2*n; i++) {
    if (s[i] == '0')
      z += 1;
    else
      z = 0;

    ans = max(ans, z);
  }

  cout << ans << '\n';
}

void solve() {
  // how many to the left is the 1?
  int n;
  cin >> n;
  string s;
  cin >> s;

  s += s;

  int away = 0, ans = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (s[i] == '1')
      away = 0;
    else
      away++;

    ans = max(away, ans);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solveOptimal();
  }
  return 0;
}
