#include <iostream>
#include <vector>

#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  if (s.find("2025") == string::npos || s.find("2026") != string::npos)
    cout << 0 << '\n';
  else
    cout << 1 << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
