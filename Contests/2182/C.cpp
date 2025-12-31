#include <iostream>
#include <vector>

#define ll long long

using namespace std;

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }

  ll ab = 0, bc = 0;

  for (int shifts = 0; shifts < n; shifts++) {
    bool fit = true;
    for (int i = 0; i < n; i++) {
      if (a[i] >= b[(shifts + i) % n]) {
        fit = false;
        break;
      }
    }
    if (fit)
      ab++;
  }

  for (int shifts = 0; shifts < n; shifts++) {
    bool fit = true;
    for (int i = 0; i < n; i++) {
      if (b[i] >= c[(shifts + i) % n]) {
        fit = false;
        break;
      }
    }
    if (fit)
      bc++;
  }

  cout << ab * bc * n << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
