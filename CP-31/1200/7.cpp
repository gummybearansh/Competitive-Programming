// 1808B
#include <bits/stdc++.h>

#define ll long long

using namespace std;

// very beautiful math heavy problem
// instead of viewing the matches individually (Nc2 matches) look at the columns individually
// each person is playing with each person, so the score of that card is involved in every match he plays
// sorting the column, now i can find out how this particular score will be counted
// in the sense -> |a - x| => (x - a) or (a - x)
// so if x > a -> x will open with +ve sign, if x < a -> x will open with -ve sign
// now i can find out the contribution of each column (since i've sorted it and I know how many smaller than it, this one will open with a + sign, and how many bigger than it -. this one will open with -ve sign);
void solveCleanerSolution() {
  int n, m;
  cin >> n >> m;
  // since i need the columns itslef -> store the columsn as the rows directly
  // now m rows, n columns
  vector<vector<ll>> v(m, vector<ll>(n));

  // go over the old input but just store it in reverse -> col/row
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[j][i];
    }
  }

  // sort each row
  for (int i = 0; i < m; i++) {
    sort(v[i].begin(), v[i].end());
  }

  // now calculate the same thing
  ll ans = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      ans += (j * v[i][j]) + (-1) * v[i][j] * (n - j - 1);
    }
  }
  cout << ans << '\n';
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<ll>> v(n, vector<ll>(m));

  for (auto &r : v) {
    for (auto &c : r)
      cin >> c;
  }

  // now look at individual columns
  ll ans = 0;
  // go over each column
  for (int j = 0; j < m; j++) {
    // go over each row
    vector<ll> tmp(n);
    for (int i = 0; i < n; i++) {
      tmp[i] = v[i][j];
    }
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < n; i++) {
      ans += (i * tmp[i]) + (-1) * (n - 1 - i) * tmp[i];
    }
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    // solve();
    solveCleanerSolution();
  }
  return 0;
}
