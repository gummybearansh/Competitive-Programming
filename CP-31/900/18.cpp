// 1624B
#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

void solve() {
  ll a, b, c;
  cin >> a >> b >> c;

  // AP: B = (C - A) / 2
  ll new_a = 2 * b - c;
  if (new_a > 0 && new_a % a == 0) {
    cout << "YES\n";
    return;
  }

  ll new_b = (c + a) / 2;
  if (new_b > 0 && new_b % b == 0 && (c - a) % 2 == 0) {
    cout << "YES\n";
    return;
  }

  ll new_c = 2 * b - a;
  if (new_c > 0 && new_c % c == 0) {
    cout << "YES\n";
    return;
  }

  cout << "NO\n";
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
