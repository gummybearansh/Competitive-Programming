// 1691B
#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  // basically iterate over all contiguous blocks - having same size - since array is sorted they'll be together
  // if R - L + 1 == 1 -> there's only one shoe - not possible
  // otherwise - L get's R's shoe, and everyone else get's the previous guy's shoe
  int l = 0;
  vector<int> res(n);
  while (l < n) {
    int r = l;
    // expand r to the end of this contiguous block
    while (r + 1 < n && v[r + 1] == v[l])
      r++;

    // check validity
    if (r - l + 1 <= 1) {
      cout << -1 << '\n';
      return;
    }

    // cyclic shifting
    // first person gets last persons shoe, everyone else get's the previous guy's shoe
    res[l] = r + 1;
    for (int i = l + 1; i <= r; i++) {
      res[i] = i;
    }

    // l goes to the start of the next block
    l = r + 1;
  }

  for (auto &x : res)
    cout << x << ' ';
  cout << '\n';
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
