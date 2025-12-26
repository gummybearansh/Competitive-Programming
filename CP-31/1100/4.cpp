// 1899C
#include <iostream>
#include <vector>

using namespace std;

#define ll long long

// solved it on my own
// 31 mins
// TC:= O(n)
// SC:= O(1)
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  ll max_sum = v[0], curr_sum = v[0], valid = 0;
  for (int i = 1; i < n; i++) {
    // cout << "m " << max_sum << ' ' << " c " << curr_sum << '\n';
    // cout << v[i] + v[i - 1] << ' ' << (v[i] + v[i - 1]) % 2 << '\n';
    // instead of checking for 1 and -1 just make it != 0
    // or even faster - just check parity individually and compare
    if (abs(v[i] % 2) != abs(v[i - 1] % 2)) {
      // modified kadanes logic
      // if (curr_sum < 0 && v[i] > curr_sum) {
      //   curr_sum = v[i];
      // } else {
      //   curr_sum += v[i];
      // }
      // can make above logic into one liner
      // is it better to add v[i] to the sum or start fresh from v[i]
      curr_sum = max((ll)v[i], v[i] + curr_sum);
    } else {
      curr_sum = v[i];
    }
    max_sum = max(max_sum, curr_sum);
  }

  cout << max_sum << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
