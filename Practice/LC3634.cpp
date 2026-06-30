// LC3634
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> nums(n);
  for (auto &i : nums)
    cin >> i;

  // find the largest balanced subarray in nums
  // longest subarray where maximum element is <= k*min
  sort(nums.begin(), nums.end());

  int j = 0, L = 0;

  // fixing the min element as i, and finding the max element
  for (int i = 0; i < n; i++) {
    // nums[i] is the min element, now i can go and find the maximum element that satisfies the required condition
    while (j < n && (ll)nums[j] <= nums[i] * k) {
      j++;
    }

    // i have an extra one in j (because condition failed on this j)
    // (j - 1) - (i) + 1 => j - i
    L = max(L, j - i);
  }

  // number of elements to remove
  cout << n - L;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
