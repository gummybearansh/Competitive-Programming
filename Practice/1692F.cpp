#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  // use frequency array more optimised our approach as well
  vector<int> freq(10, 0);
  for (auto i : v) {
    freq[i % 10]++;
  }

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        if ((i + j + k) % 10 == 3) {
          // these are the digits that we need in our array
          // do i even have them in the freq array? remove them and see if they're >= 0
          freq[i]--;
          freq[j]--;
          freq[k]--;
          if (freq[i] >= 0 && freq[j] >= 0 && freq[k] >= 0) {
            // yes they all exist
            cout << "YES\n";
            return;
          } else {
            // no they don't all exist - add them back
            freq[i]++;
            freq[j]++;
            freq[k]++;
          }
        }
      }
    }
  }

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
