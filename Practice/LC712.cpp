#include <bits/stdc++.h>
using namespace std;

int minimumDeleteSum(string s1, string s2) {
  int l1 = s1.size(), l2 = s2.size();
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  int i = 0, j = 0;
  int sum = 0;
  while (i < l1 && j < l2) {
    cout << sum << '\n';
    cout << s1[i] << ' ' << s2[j] << '\n';
    if (s1[i] != s2[j]) {
      if (s1[i] < s2[j]) {
        sum += s1[i];
        i++;
        continue;
      } else {
        sum += s2[j];
        j++;
        continue;
      }
    }
    i++;
    j++;
  }

  while (i < l1)
    sum += s1[i++];
  while (j < l2)
    sum += s2[j++];

  return sum;
}

int main() {
  string string1, string2;
  cin >> string1 >> string2;

  cout << minimumDeleteSum(string1, string2);
}
