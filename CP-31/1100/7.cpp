// 1873E
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

bool check(ll height, vector<ll> &v, ll x) {
  // find water taken by height
  ll water = 0;
  for (int i = 0; i < v.size(); i++) {
    if (height - v[i] > 0) {
      // will overflow -> need early return
      water += (height - v[i]);
      if (water > x)
        return false;
    }
  }
  if (water > x)
    return false;
  return true;
}

void solve() {
  // notice: height and water have a monotonic (steady/in one direction)
  // relationship meaning - as height increases, water will only increase, never
  // decrease BS On ans -> try to apply binary search on a range of height ->
  // Say [1 to 1e9] because, if say H is the height <= x, then all the heights
  // below it will be valid, and all the heights above it will be invalid (too
  // much) [Y Y Y Y Y N N N N N] -> so we need to find the maximum valid height
  // right? easy bs on answer implementation

  ll n, x;
  cin >> n >> x;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  ll low = 1, high = 1e18, h = 1;
  while (low <= high) {
    ll mid = low + (high - low) / 2;

    // can mid be a valid height?
    if (check(mid, v, x)) {
      h = mid;
      // now try to find bigger, (left half is useless)
      low = mid + 1;
    } else {
      // too big
      // so right half is useless, go smaller
      high = mid - 1;
    }
  }

  cout << h << '\n';
}

void solveBrute() {
  int n, x;
  cin >> n >> x;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  ll w = 0, i = 1;
  // loop until height of water required
  while (true) {
    // loop for columns
    w = 0;
    for (int j = 0; j < n; j++) {
      if (i - v[j] > 0) {
        w += (i - v[j]);
      }
    }
    if (w > x) {
      cout << i - 1 << '\n';
      return;
    }
    i++;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    // solveBrute();
    solve();
  }
}
