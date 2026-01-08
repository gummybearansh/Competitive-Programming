// 1374B
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int sumOfDigits(int n) {
  int sm = 0;
  while (n > 0) {
    sm += n % 10;
    n /= 10;
  }
  return sm;
}

void solve() {
  int n;
  cin >> n;

  int ops = 0;
  while (n > 1) {
    if (sumOfDigits(n) % 3 != 0) {
      cout << -1 << '\n';
      return;
    }

    else if (n % 2 == 0) {
      n /= 6;
    } else {
      ops++;
      n /= 3;
    }
    ops++;
  }
  cout << ops << '\n';
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
