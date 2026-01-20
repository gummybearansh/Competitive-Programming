#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solveOptimal() {
  ll n, m, h;
  cin >> n >> m >> h;
  vector<ll> v(n);
  for (auto &i : v)
    cin >> i;

  // storing all queries in this vector
  // interesting way to take pair as input with auto
  vector<pair<ll, ll>> q(m);
  for (auto &[idx, val] : q) {
    cin >> idx >> val;
    idx--;
  }

  ll reset = 0;
  for (int i = 0; i < m; i++) {
    auto [idx, val] = q[i]; // pick the query
    // do the query
    v[idx] += val;
    if (v[idx] > h) {
      // do the reset - only for values that have been changed wowowowowo? how?
      // amortised time complexity analysis - we process each query only once -> O(m), but we also undo the query only once as well, after updating, the reset is set to +1 , we never go back, so complexity of solution is O(2M)
      for (int j = i; j >= reset; j--) {
        // start at the current query index, and go till u find the last reset
        // query
        auto [idx2, val2] = q[j];
        v[idx2] -= val2;
      }
      // this is the new latest reset
      reset = i + 1;
    }
  }

  for (auto &x : v)
    cout << x << ' ';
  cout << '\n';
}

// god knows what was going on in this solution (but it worked)
void solve() {
  ll n, m, h;
  cin >> n >> m >> h;

  // <original value, <op_changed, changed_val>>
  vector<pair<ll, pair<ll, ll>>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first;
    v[i].second.second = v[i].first;
    v[i].second.first = -1;
  }

  ll recentReset = -1;
  for (int i = 0; i < m; i++) {

    // for (auto it : v)
    //   cout << it.second.second << ' ';
    // cout << '\n';

    ll b, c;
    cin >> b >> c;
    b--;

    if (v[b].second.first < recentReset && v[b].second.first != -1) {
      v[b].second.second = v[b].first;
      v[b].second.first = -1;
    }

    v[b].second.second += c;
    v[b].second.first = i;

    if (v[b].second.second > h) {
      recentReset = i;
      v[b].second.first = -1;
      v[b].second.second = v[b].first;
    }
  }

  for (int i = 0; i < n; i++) {
    if (v[i].second.first < recentReset)
      cout << v[i].first << ' ';
    else
      cout << v[i].second.second << ' ';
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    // solve();
    solveOptimal();
  }
  return 0;
}
