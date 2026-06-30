#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  // if there are no zeroes -> it's not possible. (both sides will have mex = 0)
  // (NO) if there is only 1 zero -> put it at the end now left half will be 0,
  // right will be non zero always (YES) atleast 2 zeroes -> if there are no 1s,
  // then will have to split the zeroes and both side mex will be 1 (NO) atlesat
  // 2 zeroes -> but there are 1s -> put all the zeroes at the end -> now ->
  // mex(left) = 0, mex(right) = 1, if left contains a zero -> then it will also
  // contain a 1 -> mex(left) >= 2, and mex(right) == 1 (only zeroes to the
  // right)
  vector<int> freq(n + 1);
  for (auto num : v) {
    freq[num]++;
  }

  if (freq[0] == 0)
    cout << "NO\n";
  else if (freq[0] == 1)
    cout << "YES\n";
  else if (freq[1] == 0)
    cout << "NO\n";
  else
    cout << "YES\n";
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
