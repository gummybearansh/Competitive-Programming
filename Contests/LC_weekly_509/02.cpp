class Solution {
public:
  bool canMakeSubsequence(string s, string t) {
    int n = s.size(), m = t.size();

    // s can't be longer than t
    if (n > m)
      return false;

    // prefix[i] => index in 't' matching s[0...i]
    vector<int> prefix(n, -1);
    int j = 0;
    for (int i = 0; i < n; i++) {
      while (j < m && t[j] != s[i])
        j++;

      if (j < m) {
        // this character index in 't'
        prefix[i] = j;
        j++;
      } else {
        break;
      }
    }

    // s completely got matched?
    if (prefix[n - 1] != -1)
      return true;

    // suffix[i] => index in 't' matching s[i...n-1]
    vector<int> suffix(n, -1);
    j = m - 1;
    for (int i = n - 1; i >= 0; i--) {
      while (j >= 0 && t[j] != s[i])
        j--;

      if (j >= 0) {
        suffix[i] = j;
        j--;
      } else {
        break;
      }
    }

    // there basically must be a gap of atleast 1 char between where the prefix ends and suffix begins
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        // edge case - if i replace the first char - the rest of the matching must start at index 1 or later
        if (n == 1 && m >= 1)
          return true; // s only had one letter - we directly replace it
        if (suffix[1] >= 1)
          return true;
      } else if (i == n - 1) {
        // edge case - replacing last char
        // does the beginning of 's' match before last char of 't'
        if (prefix[n - 2] != -1 && prefix[n - 2] <= m - 2)
          return true;
      } else {
        // normal case
        int left_end = prefix[i - 1];
        int right_start = suffix[i + 1];

        if (left_end != -1 && right_start != -1) {
          if (right_start - left_end > 1)
            return true;
        }
      }
    }
    return false;
  }
};
