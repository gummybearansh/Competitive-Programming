// 492B
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n, l;
  cin >> n >> l;
  vector<double> v(n);
  for (auto &i : v) {
    cin >> i;
  }

  // i don't even need binary search for this
  // just a greedy solution would work

  sort(v.begin(), v.end());

  // bounadry gaps between first lantern and 0, and last cell and last lantern (these don't get divided by 2)
  double maxD = max(v[0], l - v[n - 1]);

  // the max distance between 2 continuous lanterns - 1
  for (int i = 1; i < n; i++) {
    double gap = (v[i] - v[i - 1]) / 2;
    maxD = max(maxD, gap);
  }

  cout << fixed << setprecision(10) << maxD << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
