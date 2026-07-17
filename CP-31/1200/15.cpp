// 1692E
#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

void solve() {
  int n, s;
  cin >> n >> s;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  // handling case where total_sum < s -> not possible to remove any to make it = s
  int total_sum = 0;
  for (int i = 0; i < n; i++)
    total_sum += v[i];
  if (total_sum < s) {
    cout << -1 << '\n';
    return;
  }

  int left = 0;
  int curr_sum = 0, max_len = -1;

  // sliding window - slide to right till sum is valid
  // if exceeds move left one - keep tracking max size
  for (int right = 0; right < n; right++) {
    curr_sum += v[right];

    // shrink the window if we exeed s
    while (curr_sum > s && left <= right) {
      curr_sum -= v[left];
      left++;
    }

    if (curr_sum == s) {
      max_len = max(max_len, right - left + 1);
    }
  }

  if (max_len == -1) {
    cout << -1 << '\n';
  } else {
    cout << n - max_len << '\n';
  }
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
