// 1790D
#include <bits/stdc++.h>

#define ll long long

using namespace std;

// good beautiful problem
// see solution in notes
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  // frequqency of each element
  map<int, int> mpp;
  for (int num : v)
    mpp[num]++;

  // sorted store of values
  vector<int> it;
  for (auto p : mpp)
    it.push_back(p.first);

  int ans = mpp[it[0]];
  for (int i = 1; i < it.size(); i++) {
    // if current value - prev value > 1 => all dolls with this size need new set
    if (it[i] - it[i - 1] > 1) {
      ans += mpp[it[i]];
    } else if (mpp[it[i]] - mpp[it[i - 1]] > 0) {
      // if current value has moer count than previous value => the excess would need their own new set
      ans += mpp[it[i]] - mpp[it[i - 1]];
    }
  }

  // set count
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
