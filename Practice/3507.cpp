#include <bits/stdc++.h>
#define ll long long

using namespace std;

int minPair(vector<int> &v) {
  int n = v.size(), sum = INT_MAX, idx = -1;
  for (int i = 0; i < n - 1; i++) {
    if (v[i] + v[i + 1] < sum) {
      sum = v[i] + v[i + 1];
      idx = i;
    }
  }
  return idx;
}

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  int ops = 0;
  while (!is_sorted(v.begin(), v.end())) {
    ops++;
    int idx = minPair(v);
    v[idx] += v[idx + 1];
    v.erase(v.begin() + idx + 1);
  }

  cout << ops << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
