class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.size();
    int start = 0, mx_len = 0;

    // consider each index to be the center  O(N)
    // and expand outward to make palindrome O(N)
    for (int i = 0; i < n; i++) {
      // odd length palindrome - reflected about i
      int l = i, r = i;
      while (l >= 0 && r < n && s[l] == s[r]) {
        // keep going out
        l--;
        r++;
      }
      if (r - l - 1 > mx_len) {
        mx_len = r - l - 1; // loop goes 1 step out
        start = l + 1;      // loop goes 1 more left
      }

      // even length palindrome - i and i + 1 should be reflection
      l = i, r = i + 1;
      while (l >= 0 && r < n && s[l] == s[r]) {
        l--;
        r++;
      }
      if (r - l - 1 > mx_len) {
        mx_len = r - l - 1; // loop goes 1 step out
        start = l + 1;      // loop goes 1 more left
      }
    }
    return s.substr(start, mx_len);
  }
};
