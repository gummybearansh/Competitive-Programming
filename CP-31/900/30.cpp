// 1373B
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  string s;
  cin >> s;
  int zs = 0, os = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0')
      zs++;
    else
      os++;
  }

  int c = min(zs, os);
  if (c % 2 == 1)
    cout << "DA\n";
  else
    cout << "NET\n";
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
