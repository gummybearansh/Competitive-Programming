// LC3713
#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

int longestBalanced(string s) {
  int n = s.size();
  int ans = INT_MIN;
  // i don't even need to do n-1 becaue the j loop will validate the condition even at the first iteration
  for (int i = 0; i < n; i++) {
    // storing freq of chars in this substring
    vector<int> freq(26);
    int distinct = 0, max_freq = INT_MIN;
    for (int j = i; j < n; j++) {
      int char_idx = s[j] - 'a';


      // found a new char
      if (freq[char_idx] == 0) {
        distinct++;
      }

      freq[char_idx]++;
      max_freq = max(max_freq, freq[char_idx]);

      // now i need to check if all distinct chars have the same freqency
      // smart O(1) check
      // dbg(s[j]);
      // dbg(max_freq);
      // dbg(distinct);
      if (j - i + 1 == max_freq * distinct) {
        ans = max(ans, j - i + 1);
      }
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  cout << longestBalanced(s);
  return 0;
}
