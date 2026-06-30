#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  ll n, x;
  cin >> n >> x;

  // observation 1: use the full power of moves - for the Aith jump -> i can do pos + 1, +2, .. +Ai -> do the full power jump -> because if i can reach >= x in k moves, i can definitely reach x in the same x moves (i will jump lesser in the last one)

  // observation 2: use the free moves from all the moves available (without the rollback) -> gets me as close to x as possible

  // observation 3: now that i have to use rollbacks - i will just spam the jump that gets me farthest even after going back a bit wowowow

  ll free = 0, mx = -2e18;
  for (int i = 0; i < n; i++) {
    ll a, b, c;
    cin >> a >> b >> c;

    // add the free jump
    free += (b - 1) * a;

    // if i spam this jump, how much further will it get me when i have to use a rollback?
    ll jumpVal = (a * b) - c; // a * (b - 1) + (a - c) = ab - a + a - c

    mx = max(mx, jumpVal);
  }

  if (free >= x) {
    // no rollbacks needed
    cout << 0 << '\n';
    return;
  }

  if (mx <= 0) {
    // can't even go ahead if i use a rollback
    cout << -1 << '\n';
    return;
  }

  // now i need to spam the remaining distance using the best jump
  ll gap = x - free;
  cout << (gap + mx - 1) / mx << '\n';
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
