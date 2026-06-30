#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve(){
  int s, k, m; cin >> s >> k >> m;

  if (k <= s) {
    // every odd step -> drops from s -> s-k (drop for k duration if left unattended)
    // every even step -> drops from k -> 0 (only k sand in the top half)
    // how will u find out if step is even or odd? 
  }
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

void solveFakeeeee() {
  ll s, k, m;
  cin >> s >> k >> m;

  ll flips = m / k;
  ll rem = m % k;

  ll start;
  if (flips % 2 == 0) {
    start = s;
  } else {
    start = min(s, k);
  }

  start - rem > 0 ? cout << start - rem << '\n' : cout << 0 << '\n';

  // // max kitni der can fall in one go?
  // int val = min(s, k);
  //
  // val *(flips + 1) - m > 0 ? cout << val * (flips + 1) - m << '\n'
  //                          : cout << 0 << '\n';
}

