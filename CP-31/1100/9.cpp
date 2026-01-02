#include <iostream>
#include <vector>

#define ll long long

using namespace std;

// very important => understand why 2*mid?
// basically we're trying to find the area of the painting with w added on all 4 sides
// to find area of a square -> we just need to make sure side is correct, so if we add w to the top+bottom -> we now have a square with side s+2w
// it doesn't matter if u add it to left and right or top and bottom -> as long as the side is s+2w -> the are will be of the square we rerquire
ll cardboard(ll mid, vector<ll> &v, ll c) {
  ll used = 0;
  for (int i = 0; i < v.size(); i++) {
    v[i] += 2 * mid;
    if (v[i] > c / v[i])
      return -1;
    ll add = v[i] * v[i];
    if (used > c - add)
      return -1;
    else
      used += add;
  }
  return used;
}

void solve() {
  ll n, c;
  cin >> n >> c;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  // max w can be 10e9 -> 1 square, of size 1 and cardboard to be used = 10e18
  ll low = 0, high = 1e9;
  while (low <= high) {
    ll mid = low + (high - low) / 2;

    ll used = cardboard(mid, v, c);
    // cout << mid << ' ' << used << '\n';
    // too much, reduce w
    if (used == -1)
      high = mid - 1;
    else if (used == c) {
      cout << mid << '\n';
      return;
    } else
      low = mid + 1;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
