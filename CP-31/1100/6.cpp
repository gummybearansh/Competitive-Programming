// 1891B
// say -> bin(11000) -> number is divisible by 2^3 (3 zeroes at the end) (48 is divisible by 8)
// but if we add (2^2 to it) -> bin(11100) -> now it can only be divisble by 2^2 and 2^1 (48 + 4 = 52 divisible only by 4 and 2)
// crazyyy
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<ll> a(n), x(q);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < q; i++) {
    cin >> x[i];
  }

  // if a query is executed (x[i])
  // then the max valid next query will be (x[i]-1)
  // so the queries that are not strictly lesser than x[i] can be removed
  vector<ll> valid_x;
  valid_x.push_back(x[0]);
  for (int i = 1; i < q; i++) {
    if (x[i] < valid_x.back()) {
      valid_x.push_back(x[i]);
    }
  }

  q = valid_x.size();
  vector<ll> valid_x_vals(q);
  for (int i = 0; i < q; i++) {
    // left shift k => 2^k
    valid_x_vals[i] = (1LL << valid_x[i]);
  }

  // main checking loop
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < q; j++) {
      if (a[i] % valid_x_vals[j] == 0) {
        // right shift by 1 -> divide by 2
        a[i] += (valid_x_vals[j] >> 1LL);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}



