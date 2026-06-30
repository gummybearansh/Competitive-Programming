// 1791D
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
  // i can pre compute the 'unique' before each index
  // and i'll have the total unique as well
  // and then at each index i can decide if this is where i split it, and it'll give me the max F(a) + F(b);
  int n;
  cin >> n;
  string s;
  cin >> s;

  set<char> st;
  // unique before this index
  vector<int> ub(n);
  for (int i = 0; i < n; i++) {
    // at this index, there are these many unique before including me
    st.insert(s[i]);
    ub[i] = st.size();
  }

  if (st.size() == 1) {
    cout << 2 << '\n';
    return;
  }

  st.clear();

  vector<int> ua(n);
  for (int i = n - 1; i >= 0; i--) {
    // at this index, there are these many unique after, including me
    st.insert(s[i]);
    ua[i] = st.size();
  }

  int ans = INT_MIN;

  for (int i = 0; i < n - 1; i++) {
    ans = max(ans, ub[i] + ua[i + 1]);
  }

  cout << ans << '\n';
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
