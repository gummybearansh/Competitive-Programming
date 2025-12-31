#include <iostream>

using namespace std;

void solve() {
  int n;
  cin >> n;
  if (1900 <= n)
    cout << "Division 1\n";
  else if (1600 <= n)
    cout << "Division 2\n";
  else if (1400 <= n)
    cout << "Division 3\n";
  else
    cout << "Division 4\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
