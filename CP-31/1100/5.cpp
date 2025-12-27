// 1899B
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

// TC: O(n log N)
// SC: O(N);
void solve() {
  ll n;
  cin >> n;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  // need sequence as it is - cannot sort
  // sort(v.begin(), v.end());

  // extra space for prefix sum array
  vector<ll> pre(n);
  pre[0] = v[0];
  for (int i = 1; i < n; i++) {
    pre[i] = pre[i - 1] + v[i];
  }

  // got a WA because minSum and maxSum were just not big enough with 'INT_MIN'
  ll currSum = 0, minSum = 1e18, maxSum = -1e18, ans = 0;
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      minSum = 1e18, maxSum = -1e18;
      // inner loop runs (n/1 + n/2 + n/3 + n/4... n/n) times
      // n (1 + 1/2 + 1/3.. 1/n)
      // n (log n) -> dominating factor for TC
      for (int j = 0; j < n; j += i) {
        if (j == 0)
          currSum = pre[j + i - 1];
        else
          currSum = pre[j + i - 1] - pre[j - 1];

        // cout << "CS: " << currSum << '\n';
        minSum = min(minSum, currSum);
        maxSum = max(maxSum, currSum);
        // cout << "min: " << minSum << ' ' << "max: " << maxSum << "\n\n";
      }
      ans = max(ans, maxSum - minSum);
    }
  }

  cout << ans << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
