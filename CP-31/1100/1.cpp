// 1917B 
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// TC:- O(nLogN)
// SC:- O(n)
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  map<char, int> freq;
  int count = 0;
  vector<int> distinct(n, 0);
  for (int i = 0; i < n; i++) {
    freq[s[i]]++;
    if (freq[s[i]] == 1) {
      count++;
    }
    distinct[i] = count;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += distinct[i];
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
