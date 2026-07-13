class Solution {
public:
  int makeNum(int digitCount, int firstDigit) {
    int digit = firstDigit;
    int num = 0;
    for (int i = 0; i < digitCount; i++) {
      num *= 10;
      num += digit;
      digit++;
    }
    return num;
  }

  int countDigits(int n) {
    int ans = 0;
    while (n > 0) {
      ans++;
      n /= 10;
    }
    return ans;
  }

  vector<int> sequentialDigits(int low, int high) {
    vector<int> ans;
    int lowDigitCount = countDigits(low);
    int highDigitCount = countDigits(high);

    // basically keep building the nums till they're in our range
    while (lowDigitCount <= highDigitCount) {
      // loop for first digit
      bool flag = false;
      for (int i = 1; i <= 9 - lowDigitCount + 1; i++) {
        int num = makeNum(lowDigitCount, i);
        if (num < low)
          continue;
        if (num > high) {
          flag = true;
          break;
        }
        ans.push_back(num);
      }
      if (flag)
        break;
      lowDigitCount++;
    }

    return ans;
  }
};
