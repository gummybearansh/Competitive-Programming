// 1744C
#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

void solve() {
  int n;
  cin >> n;
  char c;
  cin >> c;

  string s;
  cin >> s;

  // duplicate
  s += s;
  n *= 2;

  if (c == 'g') {
    cout << 0 << '\n';
    return;
  }

  // start from the end
  // from each 'g' - the count becomes 0 - keep finding the next 'c' - adding the count it took to reach there
  // the max of this count is our answer
  int count = 0, mx_count = 0;
  // find the last 'g'
  int i = n - 1;
  while (i >= 0) {
    if (s[i] == 'g') {
      break;
    }
    i--;
  }
  for (; i >= 0; i--) {
    if (s[i] == 'g') {
      count = 0;
      continue;
    }
    count += 1;
    if (s[i] == c) {
      mx_count = max(mx_count, count);
    } else if (s[i] == 'g') {
      count = 0;
    }
  }

  cout << mx_count << '\n';
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
