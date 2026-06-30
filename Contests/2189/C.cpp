#include <bits/stdc++.h>

#define ll long long

using namespace std;

// very beautiful constructive algorithm (good)
// for ever i [2, n-1] -> Pi = Pj ^ i
// XOR i both side -> Pi ^ i = Pj
// for every index i -> Pi ^ i should exist to the right of it
// very interestingly -> the last position is flexible -> doesn't matter what u put there
// so if i put 1 in the last position -> meaning Pj = 1
// so Pi ^ i = 1
// Pi = i ^ 1 => meaning flip the last bit => if odd -> i-1 if even -> i+1
// so for every 2 -> n-1 index, the number's last bit is flipped
// remaining first index => put n^1
void solve() {
  int n;
  cin >> n;
  n % 2 == 0 ? cout << n << ' ' : cout << n - 1 << ' ';
  for (int i = 2; i < n; i++) {
    cout << (i ^ 1) << ' ';
  }
  cout << 1 << '\n';
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
