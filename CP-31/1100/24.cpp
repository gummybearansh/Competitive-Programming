// 1682B
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;

  // all bits set to 1
  // since twos complement of -1 = 111111...11
  int x = -1;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    if (num != i) {
      // it must participate in the swaps
      // so X must be a SUBMASK OF THIS NUMBER
      // condition: Pi & Pj = x
      // but that should be true for all Pi and Pj that are misplaced
      // can be re-written => (Pi & Pj) & X = X
      x &= num;
    }
  }
  cout << x << '\n';
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
