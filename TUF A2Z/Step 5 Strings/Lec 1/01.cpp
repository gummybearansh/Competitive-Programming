// LC 1021 - remove outermost paranthesis
#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {
  int n = s.size(), balance = 0;
  string result = "";

  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      // opening bracket -> we're going one level deeper
      // but if balance is not 0 -> this is the not outermost one
      if (balance > 0)
        result += s[i];
      balance++;
    } else {
      // we're going one level higher
      balance--;
      // but if we're still having balance, this was not the 1 -> 0 traversal
      if (balance > 0)
        result += s[i];
    }
  }

  return result;
}

int main() {
  string s;
  cin >> s;

  cout << removeOuterParentheses(s);
}
