#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

void solve() {
  int n;
  cin >> n;
  string prev;
  cin >> prev;
  int count = 1;
  for (int i = 1; i < n; i++) {
    string s;
    cin >> s;
    if (s != prev)
      count++;
    prev = s;
  }
  cout << count << '\n';
}

int main() {
  solve();
}
