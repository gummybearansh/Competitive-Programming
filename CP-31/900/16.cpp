// 1666D
#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

void solve() {
  string s, t;
  cin >> s >> t;
  // stores the chars we had to delete from the right - if we find one that's already supposed to be deleted - cooked
  vector<int> del(26, 0);

  int ps = s.length() - 1;
  int pt = t.length() - 1;

  while (ps >= 0 && pt >= 0) {
    // this is a match - valid - but make sure we haven't deleted this - same char to the right has not been deleted
    if (s[ps] == t[pt]) {
      if (del[s[ps] - 'A'] > 0) {
        // illegal - already deleted right most
        cout << "NO\n";
        return;
      }
      // legal
      ps--;
      pt--;
    } else {
      // this char should not exist - remove it
      del[s[ps] - 'A']++;
      ps--;
    }
  }
  // we matched all chars of target
  if (pt < 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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
