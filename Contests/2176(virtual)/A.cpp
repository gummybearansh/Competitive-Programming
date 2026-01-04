#include <bits/stdc++.h>

using namespace std;

// an element can be removed, if the max of elements before it is > than the
// current element. simple. keep a store of max element before it
void solveOptimal() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  int mx = v[0], ans = 0;
  for (int i = 1; i < n; i++) {
    if (mx > v[i])
      ans++;
    mx = max(mx, v[i]);
  }
  cout << ans << '\n';
}

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  // if an element is bigger, find out how many it can eat
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    if (v[i] > v[i + 1]) {
      // how many can he eat?
      int j = i + 1;
      while (j < n && v[i] > v[j]) {
        // cout << v[i] << ' ' << v[j] << '\n';
        ans++;
        j++;
      }
      i = j - 1;
    }
  }
  cout << ans << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solveOptimal();
  }
}
