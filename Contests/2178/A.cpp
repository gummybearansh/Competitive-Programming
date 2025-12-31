#include <iostream>
#include <vector>

#define ll long long;

using namespace std;

void solve() {
  string s;
  cin >> s;

  int n = s.size();
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'Y') {
      count++;
      if (count > 1) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
