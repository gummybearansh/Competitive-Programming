// LC 3379
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int &i : nums)
    cin >> i;

  vector<int> res(n);
  for (int i = 0; i < n; i++) {

    // first normalise with n, and then findwhere new idx needs to be
    int newIdx = ((nums[i] % n) + i) % n;

    // if going left, and reached out of bounds, normalise with n
    if (newIdx < 0)
      newIdx += n;

    res[i] = nums[newIdx];
  }

  for (auto i : res) {
    cout << i << ' ';
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
