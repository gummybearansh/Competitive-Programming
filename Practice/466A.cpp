// 466A
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  // if the combo is cheaper than the individual only then we'll buy it
  // smarter
  if (b < m * a) {
    // sometimes buying the bundle is cheaper even if some rides go to waste
    cout << (n / m) * b + min((n % m) * a, b) << '\n';
  } else {
    cout << n * a << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
