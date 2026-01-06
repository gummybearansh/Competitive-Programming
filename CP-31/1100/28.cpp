// 1631B
#include <bits/stdc++.h>

#define ll long long

using namespace std;

// took a little hint
// i was caring about the ones at the last and the ones in the beginning (i counted if the ones at the beginning are the same as the one's at the end, so they don't need to be washed over)
// but more pertinently -> care about the ones in the middle that are the same ->> they can be diretly added to the count and can be used to make a bigger modification wowwowow w-> handles the ones at the beginning automatically too
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  int c = 1, ops = 0, i = n - 2;
  while (i >= 0) {
    if (v[i] == v[n - 1]) {
      c++;
      i--;
    } else {
      ops++;
      i -= c;
      c *= 2;
    }
  }

  cout << ops << '\n';
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
