// 1656B
#include <bits/stdc++.h>

#define ll long long

using namespace std;

// what a beautiful solution
// suppose numbers are a1 a2 a3 a4
// remove say a4 -> a1-a4, a2-a4, a3-a4
// suppose remove 2nd -> a1-a4-(a2-a4), a3-a4-(a2-a4)
// simplify: a1-a2 a3-a2
// remove say 1st a3-a2-(a1-a2)
// a3-a1 -> so if you're leaving element at index x -> you'll be left with ax -
// ai where ai will be the last element u remove so for if any ai, if ai - k
// ---------- i'm ai, if i find ai - k => ai - (ai - k) = k exists -> then bingo
void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> v(n);
  for (auto &i : v)
    cin >> i;

  map<ll, int> mpp;
  for (int i = 0; i < n; i++) {
    mpp[v[i]]++;
  }

  for (int i = 0; i < n; i++) {
    if (mpp.find(v[i] - k) != mpp.end()) {
      cout << "YES\n";
      return;
    }
  }

  cout << "NO\n";
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
