class Solution {
public:
  string reverseWords(string s) {
    // optimal approach
    // iterate backwards in s - skipping ending whitespace till u find right boundary of a word
    // keep iterating till u find whitespace - now we have a word
    // extract this word using substring logic
    // append this exact word using .append() - highly optimised block operation
    int n = s.size();
    string ans;
    ans.reserve(n); // pre reserve space
    for (int i = n - 1; i >= 0; i--) {
      // skip trailing spaces
      if (s[i] == ' ')
        continue;

      // found right char of a word
      int right = i;

      // walk left until we hit space or end of string
      while (i >= 0 && s[i] != ' ')
        i--;

      // add space if this isn't the first word
      if (!ans.empty())
        ans += ' ';

      // append in one optimised block operation
      // s.append(source_string, start_index, length);
      ans.append(s, i + 1, right - i); // +1 beacuse we're on a space right now
    }
    return ans;
  }
};
