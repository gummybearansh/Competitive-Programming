// 1869B
#include <iostream>
#include <utility>
#include <vector>

#define ll long long

using namespace std;

ll find(pair<ll, ll> a, pair<ll, ll> b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve() {
  ll n, k, a, b;
  cin >> n >> k >> a >> b;

  vector<pair<ll, ll>> cities(n);

  for (int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    cities[i] = {x, y};
  }

  // cout << '\n';
  // // first k are major, rest are minor
  // for (int i = 0; i < n; i++) {
  //   if (i < k) {
  //     cout << "Major: " << cities[i].first << ' ' << cities[i].second <<
  //     '\n';
  //   } else {
  //     cout << "Rest: " << cities[i].first << ' ' << cities[i].second << '\n';
  //   }
  // }

  // the max can be -> direct path will be shortest, adding stops would only
  // increase this
  ll distance = find(cities[a - 1], cities[b - 1]);

  // claim: piggy will pass through at most 2 Major cities
  // if he's passing through more than 2 -> he can just take a flight directly
  // from 1st to 3rd so find the distance from a -> Major city closest to a, and
  // b -> Major city closest to b this will be the minimum price
  ll min_a = 1e18;
  for (int i = 0; i < k; i++) {
    min_a = min(min_a, find(cities[a - 1], cities[i]));
  }
  ll min_b = 1e18;
  for (int i = 0; i < k; i++) {
    min_b = min(min_b, find(cities[b - 1], cities[i]));
  }

  distance = min(distance, min_a + min_b);
  cout << distance << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
