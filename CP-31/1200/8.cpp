// 1793C
#include <bits/stdc++.h>

#define ll long long

using namespace std;

// good beautiful 
// two pointers greedy approach
// track the min and max element
// two pointers on ends [1, n-1] -> min = 1, max = n initially
// keep validating the range -> if L is min, move L forward and update min (next min will be min+1, which we don't want as edge element)
// siminlarly L can be max, R can be min or max
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  int l = 0, r = n - 1;
  int minV = 1, maxV = n;

  // need atlest 4 elements to make a valid range
  while (r - l > 2) {
    if (v[l] == minV) {
      l++;
      minV++;
    } else if (v[l] == maxV) {
      l++;
      maxV--;
    } else if (v[r] == minV) {
      r--;
      minV++;
    } else if (v[r] == maxV) {
      r--;
      maxV--;
    }

    // none of them are the extremes of the current range wow
    else {
      cout << l + 1 << ' ' << r + 1 << '\n';
      return;
    }
  }

  cout << -1 << '\n';
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
