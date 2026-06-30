// 1729D
#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> x(n);
  vector<int> y(n);

  for (auto &i : x)
    cin >> i;
  for (auto &i : y)
    cin >> i;

  for (int i = 0; i < n; i++) {
    // delta -> how much money i'm spending - how much money i have
    x[i] = y[i] - x[i];
  }

  sort(x.begin(), x.end());

  int i = 0, j = n - 1;
  int days = 0;
  // since i need two different people on each day
  // it's always best to just have 2 people go out together greedily
  while (i < j) {
    if (x[i] + x[j] >= 0) {
      days++;
      i++;
      j--;
    } else {
      i++;
    }
  }

  cout << days << '\n';
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
