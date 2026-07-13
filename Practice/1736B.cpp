#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;

  // basically construct b (n+1)
  // b[0] = a[0]
  // b[n] = a[n-1]
  // and confirm if gcd(b[i], b[i+1]) == a[i]
  vector<int> b(n + 1);
  b[0] = a[0], b[n] = a[n - 1];
  for (int i = 1; i < n; i++) {
    b[i] = lcm(a[i], a[i - 1]);
  }

  // now confirm
  for (int i = 0; i < n; i++) {
    if (a[i] != gcd(b[i], b[i + 1])) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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
