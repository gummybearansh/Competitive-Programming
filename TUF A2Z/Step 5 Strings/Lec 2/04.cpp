class Solution {
public:
  int myAtoi(string s) {
    int i = 0, n = s.size();

    // step 1 - consume all whitespace
    while (i < n && s[i] == ' ')
      i++;

    // step 2 - consume 1 sign
    int sign = 1;
    if (i < n && (s[i] == '-' || s[i] == '+')) {
      sign = (s[i] == '-') ? -1 : 1;
      i++;
    }

    // step 3 - consume digits - terminate instantly on anything else
    int ans = 0;
    while (i < n && s[i] >= '0' && s[i] <= '9') {
      int digit = s[i] - '0';

      // overflow guard - we're going to * 10 and add digit
      // if * 10 is causing overflow we stop there
      // if * 10 is fine we need to make sure the digit we're adding doesnt casue overflow
      if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > INT_MAX % 10)) {
        return sign == 1 ? INT_MAX : INT_MIN;
      }

      ans = ans * 10 + digit;
      i++;
    }

    return ans * sign;
  }
};
