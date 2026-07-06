// 1659 A
#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

void solve() {
  int n, r, b;
  cin >> n >> r >> b;

  // b blues will create b + 1 buckets
  // each bucket will have atleast r / (b + 1) reds
  // and the left overs we'll put one by one

  int buckets = b + 1;
  int reds = r / (b + 1);     // this many reds in each bucket
  int leftover = r % (b + 1); // this we'll add one by one in each bucket till we run out

  string s;
  s.reserve(n);
  for (int i = 0; i < buckets; i++) {
    if (leftover > 0) {
      s.append(reds + 1, 'R');
      leftover--;
    } else {
      s.append(reds, 'R');
    }
    // end of each bucket - put a 'b' - unless it's the last bucket - then skip
    if (i == buckets - 1)
      continue;
    s += 'B';
  }
  cout << s << '\n';
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
