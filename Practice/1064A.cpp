#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int ops = 0;

  while (a + b <= c) {
    a <= b ? a++ : b++;
    ops++;
  }
  while (a + c <= b) {
    a <= c ? a++ : c++;
    ops++;
  }

  while (c + b <= a) {
    // cout << a << ' ' << b << ' ' << c << '\n';
    c <= b ? c++ : b++;
    ops++;
  }

  cout << ops << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
