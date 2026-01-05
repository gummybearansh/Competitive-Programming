#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> v(n);
  for (auto &i : v)
    cin >> i;

  map<ll, ll> mpp;
  for (auto i : v) {
    mpp[i]++;
  }

  ll ans = mpp.size();
  vector<pair<ll, ll>> vp(mpp.begin(), mpp.end());

  sort(vp.begin(), vp.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b) {
    return a.second < b.second;
  });

  for (int i = 0; i < vp.size(); i++) {
    if (vp[i].second <= k) {
      ans--;
      k -= vp[i].second;
    }
  }

  if (ans <= 0)
    cout << 1 << '\n';
  else
    cout << ans << '\n';
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
