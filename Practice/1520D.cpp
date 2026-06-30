#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v) {
    cin >> i;
  }

  map<int, int> mpp;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int val = v[i] - i;
    // how many times this value exists in the map -> that many more pairs this current element will make
    ans += mpp[val];
    // and add/update this value as well
    mpp[val]++;
  }
  cout << ans << '\n';
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
