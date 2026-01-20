// 1859B
#include <bits/stdc++.h>

#define ll long long

using namespace std;

pair<ll, ll> getMinAndSecondMin(vector<ll> &v){
  ll n = v.size();
  
  ll mn = LLONG_MAX, secondMn = LLONG_MAX;
  for (int i = 0; i < n; i++){
    if (v[i] <= mn){
      secondMn = mn;
      mn = v[i];
    }
    else if (v[i] < secondMn){
      secondMn = v[i];
    }
  }

  return {mn, secondMn};
}

void solve() {
  int n;
  cin >> n;

  // u have n arrays
  // the best each array can do is contribute it's second min element
  // but one will contribute it's actual min element (we're basically throwing
  // the mins into one array) so we'll pick the array with the least second min
  // to dump all the mins into
  ll ans = 0, mn = INT_MAX, mn_second = INT_MAX;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    vector<ll> v(m);
    for (int i = 0; i < m; i++) {
      cin >> v[i];
    }

    sort(v.begin(), v.end());
    mn = min(mn, v[0]);
    mn_second = min(mn_second, v[1]);
    ans += v[1];
  }

  // from the answer, we'll remove the second min that contributes the least (is
  // minimum) and add the actual global min value
  ans -= mn_second;
  ans += mn;

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
