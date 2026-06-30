// 230A
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int s, n;
  cin >> s >> n;

  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    int t1, t2;
    cin >> t1 >> t2;
    v[i].first = t1;
    v[i].second = t2;
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < n; i++) {
    if (s <= v[i].first) {
      cout << "NO\n";
      return;
    } else {
      s += v[i].second;
    }
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
