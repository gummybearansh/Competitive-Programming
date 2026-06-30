// 1742E
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> v(n);
  vector<int> qq(q);

  for (int &i : v)
    cin >> i;
  for (int &i : qq)
    cin >> i;

  // prefix sum -> the height corresponding to the step u can takej
  vector<ll> pfS(n, 0);
  pfS[0] = v[0];
  for (int i = 1; i < n; i++) {//n
    pfS[i] = pfS[i - 1] + v[i];
  }

  // prefix max -> the max step u can reach
  vector<int> pfM(n, 0);
  pfM[0] = v[0];
  for (int i = 1; i < n; i++) {//n
    pfM[i] = max(pfM[i - 1], v[i]);
  }

  // binary search to find the upper bound on pfM (smallest step he can't climb) and the just previous one would be the one i can, and the pfS will give me the max corresponding height
  for (int i = 0; i < q; i++) {//q
    int num = qq[i];
    int idx = upper_bound(pfM.begin(), pfM.end(), num) - pfM.begin(); //log(n)
    idx--;
    // step is too small, can't even climb the firstO(2n) - 2 precomputation array
    if (idx < 0) {
      cout << 0 << ' ';
    } else
      cout << pfS[idx] << ' ';
  }
  cout << '\n';
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
