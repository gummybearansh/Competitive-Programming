#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  int l = 0, r = n - 1;
  int s1 = 0, s2 = 0;
  bool turn = true;

  while (l <= r) {
    int val;
    if (v[l] <= v[r]) {
      val = v[r];
      r--;
    } else {
      val = v[l];
      l++;
    }
    if (turn) {
      s1 += val;
      turn = false;
    } else {
      s2 += val;
      turn = true;
    }
  }

  cout << s1 << ' ' << s2 << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
