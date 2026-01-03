#include <iostream>

#define ll long long

using namespace std;

void solve() {

  ll num;
  cin >> num;

  // 3 distinct positive divisors -> square of a prime number

  // find square root
  ll low = 2, high = num, root = 0;
  while (low <= high) {
    ll mid = low + (high - low) / 2;

    if (mid > num / mid) {
      // too big, find smaller
      high = mid - 1;
    } else if (mid * mid == num) {
      root = mid;
      break;
    } else {
      // too small, find bigger
      low = mid + 1;
    }
  }

  // check if root exists, and if it's prime
  if (root) {
    for (int i = 2; i * i <= root; i++) {
      if (root % i == 0) {
        cout << "NO\n";
        return;
      }
    }
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    solve();
  }
}
