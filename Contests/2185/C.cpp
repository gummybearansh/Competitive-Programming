#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  if (n == 1) {
    cout << 1 << '\n';
    return;
  }

  sort(v.begin(), v.end());

  // for (auto it : v)
  //   cout << it << ' ';
  // cout << '\n';

  int seq = 1, maxSeq = 1;
  for (int i = 1; i < n; i++) {
    if (v[i] - v[i - 1] == 0)
      continue;
    if (v[i] - v[i - 1] == 1) {
      // cout << v[i] << ' ';
      seq++;
      // cout << '\n' << seq << '\n';
    } else {
      maxSeq = max(seq, maxSeq);
      seq = 1;
    }
  }

  cout << max(seq, maxSeq) << '\n';
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
