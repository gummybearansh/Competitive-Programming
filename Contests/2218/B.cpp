#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

void solve() {
  vector<int> v(7);

  for (int &i : v) {
    cin >> i;
  }

  sort(v.begin(), v.end());
  int sum = 0;
  for (int i = 0; i < 7; i++) {
    if (i == 6)
      sum += v[i];
    else
      sum -= v[i];
  }

  cout << sum << '\n';
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
