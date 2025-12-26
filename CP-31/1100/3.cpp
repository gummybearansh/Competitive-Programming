#include <algorithm>
#include <iostream>
#include <utility> // pairs is in utility
#include <vector>
// #include <bits/stdc++.h>
using namespace std;

#define ll long long

// TC:= O(NlogN))
// SC:= O(N)
// pretty interesting dp solution - refer to notes
void solve() {
  int n;
  cin >> n;

  // store value in pair {value, original_idx}
  vector<pair<ll, int>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first;
    v[i].second = i;
  }

  // Sort based on values
  sort(v.begin(), v.end());

  // Prefix sum
  vector<ll> pref(n);
  pref[0] = v[0].first;
  for (int i = 1; i < n; i++) {
    pref[i] = pref[i - 1] + v[i].first;
  }

  vector<int> ans(n);
  // the last element can always reach itself
  ans[n - 1] = n - 1;

  // Backward Iteration Optimisation
  for (int i = n - 2; i >= 0; i--) {
    // logic - u do start of with yourself
    if (pref[i] >= v[i + 1].first) {
      // if i can eat the guy ahead of me -> then i can go as far as he goes
      ans[i] = ans[i + 1];
    } else {
      // else i can only eat the people before me - and there are (i) people
      // before me
      ans[i] = i;
    }
  }

  // Final ans needs to be in original order
  vector<int> final_ans(n);
  for (int i = 0; i < n; i++) {
    final_ans[v[i].second] = ans[i];
  }

  for (int i = 0; i < n; i++) {
    cout << final_ans[i] << ' ';
  }
  cout << '\n';
}

// o(n^2) solution - bad
void solveBrute() {
  int n;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  vector<long long> copy(n);
  for (int i = 0; i < n; i++) {
    copy[i] = v[i];
  }
  sort(copy.begin(), copy.end());

  long long score = 0;
  int removed = 0;
  bool skip = true;
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    score = v[i];
    removed = 0;
    skip = true;
    for (int j = 0; j < n; j++) {
      if (copy[j] <= score) {
        if (skip && v[i] == copy[j]) {
          skip = false;
          continue;
        }
        score += copy[j];
        removed++;
      }
    }
    ans[i] = removed;
    // cout << v[i] << ' ' << score << ' ' << removed << '\n';
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
