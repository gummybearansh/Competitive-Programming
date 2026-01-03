#include <iostream>
#include <vector>

#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<ll> v(n), v_p(n);
  for (auto &it : v)
    cin >> it;
  for (auto &it : v_p)
    cin >> it;

  // simple
  // find where the change happened
  // expand out from there to find the sorted portion
  int l = 0, r = n - 1;
  for (int i = 0; i < n; i++) {
    if (v[i] != v_p[i]) {
      l = i;
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (v[i] != v_p[i]) {
      r = i;
      break;
    }
  }

  // expand outwards
  while (l > 0 && v_p[l] >= v_p[l - 1]) {
    l--;
  }
  while (r < n - 1 && v_p[r] <= v_p[r + 1]) {
    r++;
  }

  cout << l + 1 << ' ' << r + 1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    solve();
}
