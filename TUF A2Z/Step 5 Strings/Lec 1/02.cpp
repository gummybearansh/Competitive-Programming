// LC 151 - reverse words in a string
#include <bits/stdc++.h>
#include <string>
using namespace std;

string reverseWords(string s) {
  int n = s.size();

  // reverse entire string
  reverse(s.begin(), s.end());

  // reverse each word in place
  int start = 0;
  for (int i = 0; i <= n; i++) {
    // if we hit space or end of string
    if (i == n || s[i] == ' ') {
      reverse(s.begin() + start, s.begin() + i);
      start = i + 1;
    }
  }

  // space clean up logic
  int write = 0, read = 0;
  while (read < n) {
    while (read < n && s[read] == ' ') {
      read++;
    }

    if (read == n)
      break;

    if (write > 0) {
      s[write++] = ' ';
    }

    while (read < n && s[read] != ' ') {
      s[write] = s[read];
      write++;
      read++;
    }
  }
  return s;
}

int main() {
  string s;
  getline(cin, s);
  cout << s << '\n';
  cout << reverseWords(s);
}
