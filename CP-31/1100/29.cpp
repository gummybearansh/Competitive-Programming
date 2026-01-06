// 1618C
#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

void solve() {
  // if we find a d that divides all even/all odd indexes, and none of their
  // counterpart -> we win
  int n;
  cin >> n;
  vector<ll> v(n);
  for (auto &it : v)
    cin >> it;

  ll ge = v[0], go = v[1];
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      ge = gcd(ge, v[i]);
    } else {
      go = gcd(go, v[i]);
    }
  }

  // now make sure ge doesn't divide any odd index
  bool chk = false;
  for (int i = 1; i < n; i += 2) {
    if (v[i] % ge == 0) {
      chk = true;
      break;
    }
  }

  // if it didnt divide yay
  if (!chk) {
    cout << ge << '\n';
    return;
  }

  // this mean's it did divide, now check for evne idx
  chk = false;
  for (int i = 0; i < n; i += 2) {
    if (v[i] % go == 0) {
      chk = true;
      break;
    }
  }

  if (!chk) {
    cout << go << '\n';
    return;
  }

  cout << 0 << '\n';
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
