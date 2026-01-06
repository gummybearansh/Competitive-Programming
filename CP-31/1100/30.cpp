// 1610B
#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool isPalindrome(vector<int> &v, int skip) {
  int n = v.size();
  int l = 0, r = n - 1;
  while (l <= r) {
    if (v[l] == skip) {
      l++;
      continue;
    }
    if (v[r] == skip) {
      r--;
      continue;
    }
    if (v[l] != v[r]) {
      return false;
    }

    l++;
    r--;
  }

  return true;
}

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  int i = 0, j = n - 1, deleted = -1;
  while (i <= j) {
    // if u find a mismatch -> delete either of those and try to check if
    // they're a palindrome
    if (v[i] != v[j]) {
      if (isPalindrome(v, v[i])) {
        cout << "YES\n";
        return;
      }
      if (isPalindrome(v, v[j])) {
        cout << "YES\n";
        return;
      }

      cout << "NO\n";
      return;
    }

    i++;
    j--;
  }

  // here if the string itself is a palindrome
  cout << "YES\n";
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
