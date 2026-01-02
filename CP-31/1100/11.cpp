#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

// basically can't just look at what's lesser - the sum of min 2 or the max one.
// that's wrong instead u try to find the state of the sum after the k
// operations basically u need to do k operations if u do 'remove the 2 min
// elements' x times u do remove max elements k - x times and i can just iterate
// over x from 0 to k and i'll have all possible sequences of operations
// completed.
void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  vector<ll> pf(n + 1, 0);
  for (int i = 0; i < n; i++) {
    pf[i + 1] = pf[i] + v[i];
  }

  ll ans = 0;
  // iterate for x = 0 to k (inclusive)
  for (int x = 0; x <= k; x++) {

    int start_idx = 2 * x;
    int end_idx = n - (k - x);
    // We want sum of v[start_index ... end_index-1]
    // Using our pf array (where pf[i] stores sum of first i elements):
    // Sum = pf[end_index] - pf[start_index]
    ll sum = pf[end_idx] - pf[start_idx];
    ans = max(ans, sum);
  }

  cout << ans << '\n';
}

void solveGreedyLocalWrong() {
  int n, k;
  cin >> n >> k;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  for (auto it : v)
    cout << it << ' ';
  cout << '\n';

  vector<ll> pf(n);
  pf[0] = v[0];
  for (int i = 1; i < n; i++) {
    pf[i] = pf[i - 1] + v[i];
  }

  for (auto it : pf) {
    cout << it << ' ';
  }
  cout << '\n';

  ll maxSum = pf[n - 1];
  int i = 1, j = n - 1;
  while (k--) {
    cout << maxSum << '\n';
    if (v[j] <= pf[i]) {
      maxSum -= v[j];
      j--;
    } else {
      if (i == 1) {
        maxSum -= pf[i];
      } else {
        maxSum -= (pf[i] - pf[i - 2]);
      }
      i += 2;
    }
  }

  cout << maxSum << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
