#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast                   \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);

struct Trie {
  struct Node {
    int nxt[2];
    Node() {
      nxt[0] = nxt[1] = -1;
    }
  };

  vector<Node> tr;

  Trie() {
    tr.push_back(Node());
  }

  void clear() {
    tr.clear();
    tr.push_back(Node());
  }

  void insert(int x) {
    int cur = 0;
    for (int b = 30; b >= 0; b--) {
      int bit = (x >> b) & 1;
      if (tr[cur].nxt[bit] == -1) {
        tr[cur].nxt[bit] = (int)tr.size();
        tr.push_back(Node());
      }
      cur = tr[cur].nxt[bit];
    }
  }

  int max_xor(int x) {
    int cur = 0, ans = 0;
    for (int b = 30; b >= 0; b--) {
      int bit = (x >> b) & 1;
      int want = bit ^ 1;
      if (tr[cur].nxt[want] != -1) {
        ans |= (1 << b);
        cur = tr[cur].nxt[want];
      } else {
        cur = tr[cur].nxt[bit];
      }
    }
    return ans;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;

  Trie trie;
  trie.insert(a[0]);

  int ans = 0;
  for (int i = 1; i < n; i++) {
    ans = max(ans, trie.max_xor(a[i]));
    trie.insert(a[i]);
  }

  cout << ans << '\n';
}

int main() {
  fast

      int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
