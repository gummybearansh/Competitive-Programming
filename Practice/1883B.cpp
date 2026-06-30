// 1883B
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  if (n == 1) {
    cout << "YES\n";
    return;
  }

  map<char, int> mpp;
  for (auto c : s) {
    mpp[c]++;
  }

  // now string is a palindrome
  // i just need to remove the odds
  int odds = 0;
  for (auto &[c, f] : mpp) {
    if (f % 2 == 1) {
      odds++;
    }
  }

  if (odds - k <= 1)
    cout << "YES\n";
  else
    cout << "NO\n";
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
