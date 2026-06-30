#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

void solve() {
  string n;
  cin >> n;
  string ans = "";

  for (int i = 0; i < n.size(); i++) {
    int digit = n[i] - '0';

    if (i == 0 && digit == 9)
      digit = 9;
    else if (digit >= 5)
      digit = 9 - digit;

    char ch = digit + '0';
    ans += ch;
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
