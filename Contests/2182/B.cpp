#include <iostream>
#include <vector>

#define ll long long

using namespace std;

void solve() {
  ll a, b;
  cin >> a >> b;

  if (a < 2 && b < 2) {
    cout << 1 << '\n';
    return;
  }

  ll layer = 1;
  ll odd = 1, even = 0;
  for (int i = 0; i < 1e7; i++) {
    layer = (layer << 1);
    // cout << " L " << i + 1 << " odd " << odd << " even " << even << '\n';
    if (i % 2 == 0) {
      even += layer;
    } else {
      odd += layer;
    }

    if (!((a >= even && b >= odd) || (a >= odd && b >= even))) {
      cout << i + 1 << '\n';
      return;
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
