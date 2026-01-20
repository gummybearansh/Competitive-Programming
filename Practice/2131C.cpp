// somewhat beautiful, couldn't solve it on my own and uses ANOTHER mod concept
#include <bits/stdc++.h>

#define ll long long

using namespace std;

// i can basically do x + ik for each element
// but when i'm subtracting, the last positive value of x will be (x % k)
// further subtracting i'll get k - (x % k)
// so each term of S and T can be expressed as (x % k) or k - (x % k)
void solve() {
  int n, k;
  cin >> n >> k;
  map<int, int> mpp;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    mpp[t % k]++;
    mpp[k - (t % k)]++;
  }
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    mpp[t % k]--;
    mpp[k - (t % k)]--;
  }

  for (auto &[val, freq] : mpp) {
    if (freq != 0) {
      cout << "NO\n";
      return;
    }
  }
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
