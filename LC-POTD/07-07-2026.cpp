class Solution {
public:
  long long sumAndMultiply(int n) {
    string s = to_string(n);

    n = s.size();
    long long x = 0, sum = 0;
    for (int i = 0; i < n; i++) {
      int digit = s[i] - '0';
      if (digit == 0)
        continue;

      sum += digit;
      x *= 10;
      x += digit;
    }

    return x * sum;
  }
};
