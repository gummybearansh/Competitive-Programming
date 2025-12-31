#include <iostream>
#include <vector>

#define ll long long;

using namespace std;

void upsolve() {
  // there are three possibilities for each element in the array -> (don't pick
  // it) X, (picked as second element: w/ minus) -, (picked out as first: w/
  // positive) + rules: 1st Element can be either X or + (cant be - bceause - is
  // for second element) Every element after u select an X (don't pick it) will
  // be picked with - sign (they all become second element since the element not
  // chosen becomes the first)
  // observation -> with these rules in place, the elements between first and X
  // element can be + or - ex: -2 -3 4 10 -9
  //      +  - +  X  - (2, 1, 1, 2)
  //      +  + -  x - (1, 2, 1, 2) so it's always possible to fill in the values
  //      between first and X with either sign
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  vector<long long> pf(n), sf(n);
  // prefix needs to be maxed out -> abs(element) because can take either sign
  // prefix of 1st element = 0, 2nd = v[0] as it is no abs
  pf[0] = 0;
  pf[1] = v[0];
  for (int i = 2; i < n; i++) {
    pf[i] = pf[i - 1] + abs(v[i - 1]);
  }
  // for suffix -> 1st element cant be taken (either X or +), and every other
  // element goes as -
  sf[n - 1] = 0;
  sf[n - 2] = -v[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    sf[i] = sf[i + 1] - v[i + 1];
  }

  long long ans = -1e18;
  // go over each element and try to see if it is a valid (X)
  for (int i = 0; i < n; i++) {
    ans = max(ans, pf[i] + sf[i]);
  }

  cout << ans << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    upsolve();
  }
}
