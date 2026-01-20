#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n, t;
  cin >> n >> t;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;
  int k = 0, sum = 0, count = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    sum += v[i];
    if (sum <= t) {
      count++;
    } else {
      sum -= v[k];
      k++;
    }
    ans = max(ans, count);
  }

  cout << count << ' ';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
