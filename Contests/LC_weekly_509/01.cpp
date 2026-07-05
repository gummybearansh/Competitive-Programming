class Solution {
public:
  int dig_range(int n) {
    int mn = INT_MAX, mx = INT_MIN;
    while (n > 0) {
      int digit = n % 10;
      n /= 10;

      mn = min(mn, digit);
      mx = max(mx, digit);
    }

    return mx - mn;
  }

  int mx_range = INT_MIN;
  int sum = 0;
  int maxDigitRange(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int range = dig_range(nums[i]);
      if (range > mx_range) {
        mx_range = range;
        sum = nums[i];
      } else if (range == mx_range) {
        sum += nums[i];
      }
    }

    return sum;
  }
}
