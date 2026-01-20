#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  // maps color, positions
  vector<vector<int>> mpp(k + 1);
  // idx maps color, and vector maps positions
  // pushed 0 and n as positions for each (calculation of gap)
  for (int i = 1; i <= k; i++) {
    mpp[i].push_back(0);
  }

  for (int i = 0; i < n; i++) {
    mpp[v[i]].push_back(i + 1);
  }

  for (int i = 1; i <= k; i++) {
    mpp[i].push_back(n + 1);
  }

  // for (int i = 1; i <= k; i++) {
  //   cout << i << '\n';
  //   for (int j = 0; j < mpp[i].size(); j++) {
  //     cout << mpp[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  // now just need to calculate the max gap and second max gap and do some
  // voodoo magic
  int ans = INT_MAX;

  for (int i = 1; i <= k; i++) {
    int maxGap = 0, secondMaxGap = 0;
    for (int j = 1; j < mpp[i].size(); j++) {
      int currGap = mpp[i][j] - mpp[i][j - 1] - 1;
      if (currGap > maxGap) {
        secondMaxGap = maxGap;
        maxGap = currGap;
      } else if (currGap > secondMaxGap) {
        secondMaxGap = currGap;
      }
    }

    // apply the one paint
    maxGap = max(secondMaxGap, maxGap / 2);
    ans = min(ans, maxGap);
  }

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
