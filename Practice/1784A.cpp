// 1784A
#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

void solve() {
  // i need to make it a sequence of 1, 2, 3 (duplciates allowed)
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  sort(v.begin(), v.end());

  ll cost = 0, needed = 1;
  // first number needs to be 1, next 2 like that
  for (int i = 0; i < n; i++) {
    if (v[i] >= needed) {
      cost += (v[i] - needed);
      needed++;
    }
    // if < needed -> it's a duplicate number we just skip
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
