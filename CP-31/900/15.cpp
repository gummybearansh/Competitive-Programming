// 1675B
#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<ll> v(n);
  for (auto &i : v) {
    cin >> i;
  }

  // start from reverse -> divide each element / 2 till it's smaller than the one in front (count ops)
  // if the element in front is 0 -> not possible to make this element strictly smaller -> -1
  int ops = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (v[i + 1] == 0) {
      cout << -1 << '\n';
      return;
    }

    while (v[i] >= v[i + 1]) {
      v[i] /= 2;
      ops++;
    }
  }
  cout << ops << '\n';
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
