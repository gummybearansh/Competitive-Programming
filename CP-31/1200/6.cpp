// 1832C
// good learning
// beautiful
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solveClean() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  // if you have [5, 5], difference is 0, removing one changes nothing -> remove redundancy
  // [1, 5, 10] -> you don't need the middle elments, you just need the peak and valley -> 1-5 + 5-10 == 1 - 10
  // algorithm:
  //    remove adjacent duplicates
  //    count indices where v[i] is strictly greater/smaller than neighbours (peak/valley)
  //    add 2 -> start and end are always kept

  // unique -> shuffles duplicates to the end, and returns an iterator to the new 'end', subtract begin to get the new size
  n = unique(v.begin(), v.end()) - v.begin();

  // edge case handling (now there are no duplciates) if 1 value, answer is 1, if 2 unique values, answer is 2, cant have peak/valley in <3 numbers
  if (n <= 2) {
    cout << n << '\n';
    return;
  }

  // count peaks and valleys
  int ans = 2;
  for (int i = 1; i < n - 1; i++) {
    if (v[i] < v[i - 1] && v[i] < v[i + 1])
      ans++;
    else if (v[i] > v[i - 1] && v[i] > v[i + 1])
      ans++;
  }
  cout << ans << '\n';
}

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  int ans = 1;
  bool inc, dec, flat = true;
  for (int i = 0; i < n - 1; i++) {
    if (v[i] == v[i + 1])
      continue;
    if (v[i] > v[i + 1]) {
      dec = true;
      inc = false;
      flat = false;
      break;
    } else {
      inc = true;
      dec = false;
      flat = false;
      break;
    }
  }

  if (flat) {
    cout << 1 << "\n";
    return;
  }

  for (int i = 0; i < n - 1; i++) {
    if (v[i] == v[i + 1])
      continue;

    if (v[i] > v[i + 1] && inc) {
      ans++;
      dec = true;
      inc = false;
    } else if (v[i] < v[i + 1] && dec) {
      ans++;
      dec = false;
      inc = true;
    }
  }
  cout << ans + 1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solveClean();
  }
  return 0;
}
