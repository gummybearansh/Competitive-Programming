// 1831B
#include <bits/stdc++.h>

#define ll long long

using namespace std;

// helper function to get the max consecutive subarray size for each element
// TC of helper: O(n);
map<int, int> getMaxConsecutive(vector<int> &v, int n) {
  map<int, int> mpp;
  int curr = 1;
  mpp[v[0]] = 1;
  for (int i = 1; i < n; i++) {//n
    if (v[i] == v[i - 1]) {
      curr++;
    } else {
      curr = 1;
    }
    mpp[v[i]] = max(mpp[v[i]], curr);
  }
  return mpp;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (auto &i : a)
    cin >> i;
  for (auto &i : b)
    cin >> i;

  // store continuous subarray of each element in both arrays
  // the ans will be max(sum of both frequencies)
  map<int, int> mppA = getMaxConsecutive(a, n);//n
  map<int, int> mppB = getMaxConsecutive(b, n);//n

  int ans = INT_MIN;
  // dumbest way is to just go over all the elements once again
  for (int num : a) {//n
    ans = max(ans, mppA[num] + mppB[num]);
  }
  for (int num : b) {//n
    ans = max(ans, mppB[num] + mppA[num]);
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
