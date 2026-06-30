// LC3713
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int minimumDeletionsOptimal(string s) {
  int n = s.size();
  int bCount = 0, deletions = 0;

  for (int i = 0; i < n; i++) {
    if (s[i] == 'b')
      bCount++;
    else {
      if (bCount > 0) {
        deletions++;
        // simulating removing the b from the stack
        bCount--;
      }
      // if there were no bs before this, doesnt matter right
      // but i should reset it? no. because i will always have to delete if i'm pushing 'a' on top of a 'b' so b count cannot be reset, it will be brought down to 0 if the As keep on piling automatically
    }
  }

  return deletions;
}

int minimumDeletionsUnoptimal(string s) {
  int n = s.size();

  vector<char> sk;
  sk.push_back(s[0]);
  int count = 0;

  for (int i = 1; i < n; i++) {
    // if duplicate -> no problem
    if (sk.back() == s[i])
      sk.push_back(s[i]);
    // problematic ->
    else if (sk.back() == 'b' && s[i] == 'a') {
      // problematic -> pushng a on top of b
      count++;
      // remove this pair (only one was pushed)
      sk.pop_back();
    } else
      sk.push_back(s[i]);
  }

  return count;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  cout << minimumDeletionsOptimal(s);
}
