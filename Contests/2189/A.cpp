#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  // also don't need to actually sort, can just find the number of valid ones for h and l and ans will be the same thing
  int n, h, l;
  cin >> n >> h >> l;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  int cnt_l = 0, cnt_h = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] <= l)
      cnt_l++;
    if (v[i] <= h)
      cnt_h++;
  }

  // essentially -> max pairs = valid numbers for bigger range / 2;
  // min pairs -> the valid numbers for the smaller dimension
  // min(smaller, larger/2)
  cout << min(max(cnt_l, cnt_h) / 2, min(cnt_l, cnt_h)) << '\n';
}

void solveAlternate() {
  int n, h, l;
  cin >> n >> h >> l;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  sort(v.begin(), v.end());

  // from h and l, the max number of pairs will be the bigger range
  // and the min will be the pairs the smaller range can make
  int cnt_h = 0, cnt_l = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] > h && v[i] > l)
      break;
    if (v[i] <= h)
      cnt_h++;
    if (v[i] <= l)
      cnt_l++;
  }

  cout << min(max(cnt_h, cnt_l) / 2, min(cnt_h, cnt_l)) << '\n';
}

// was making the pairs, just need to count.
void solveBad() {
  int n, h, l;
  cin >> n >> h >> l;

  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  if (h < l)
    swap(l, h);
  // now l is the smaller one
  sort(v.begin(), v.end());

  int idx_h = 0;
  for (; idx_h < n; idx_h++) {
    if (v[idx_h] > h)
      break;
  }
  idx_h--;

  int idx_l = 0;
  int ans = 0;
  while (idx_l < idx_h) {
    if (v[idx_l] <= l && v[idx_h] <= h) {
      ans++;
      idx_l++;
      idx_h--;
    } else {
      break;
    }
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
