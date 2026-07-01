// 1665B
#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v) {
    cin >> i;
  }

  // find most frequent element from the array using a map
  map<int, int> mpp;
  int mx_count = 0;
  for (int i = 0; i < n; i++) {
    mpp[v[i]] += 1;
    mx_count = max(mx_count, mpp[v[i]]);
  }

  int ops = 0;
  // need to make it equal to n
  while (mx_count < n) {
    // we cloned the array
    ops++;
    // we double the mx_frequent each time
    if (mx_count * 2 < n) {
      ops += mx_count;
      mx_count *= 2;
    } else {
      // doubling them is too much - i just need to substitute remaining ones
      ops += n - mx_count;
      break;
    }
  }

  cout << ops << '\n';
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
