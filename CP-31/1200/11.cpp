// 1734C
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  // iterate over k, over entire array again and again?
  // won't that be O(n^2)?
  // let's try
  int n;
  cin >> n;
  string t;
  cin >> t;

  ll cost = 0;
  // iterate over k 1 -> N
  for (int k = 1; k <= n; k++) {
    // iterate over multiples of k
    for (int i = k; i <= n; i += k) {
      // converting 1 based indexing to 0, but still get benifits of multiples (1 based)
      int idx = i - 1;

      if (t[idx] == '1') {
        // this exists in S, and this is the smallest multiple: this k is now useless
        break;
      } else if (t[idx] == '0') {
        // remove this one wow, add it to cost
        cost += k;
        t[idx] = 2; // so i don't remove it again accidentally
      }
    }
  }
  cout << cost << '\n';
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
