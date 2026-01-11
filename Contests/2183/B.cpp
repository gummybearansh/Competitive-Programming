#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  sort(v.begin(), v.end());

  vector<int> vD;
  vD.push_back(v[0]);
  for (int i = 1; i < n; i++) {
    if (v[i] != v[i - 1])
      vD.push_back(v[i]);
  }

  int ans = 0;
  for (int i = 0; i < vD.size(); i++) {
    if (vD[i] == ans)
      ans++;
    else
      break;
  }

  if (ans > k - 1)
    ans = k - 1;
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
