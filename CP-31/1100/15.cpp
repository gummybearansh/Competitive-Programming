// 1820B

#include <bits/stdc++.h>

#define ll long long

using namespace std;

// if u have k consecutive 1s
// k x 1
// (k-1) x 2
// (k-2) x 3
// etc so k+1 is sum of width and height -> maximise product of this 
void solve() {
  string s;
  cin >> s;
  s += s;

  ll n = s.size();

  ll c = 0, mxC = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1')
      c++;
    else
      c = 0;

    mxC = max(mxC, c);
  }

  if (mxC == n) {
    cout << (n / 2) * (n / 2) << '\n';
    return;
  }

  ll t = mxC + 1;
  ll s1 = t / 2;
  ll s2 = t - s1;
  cout << s1 * s2 << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
