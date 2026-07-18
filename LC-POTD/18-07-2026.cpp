class Solution {
public:
  int findGCD(vector<int> &nums) {
    int n = nums.size();
    int min_num = INT_MAX, max_num = INT_MIN;
    for (auto i : nums) {
      min_num = min(min_num, i);
      max_num = max(max_num, i);
    }
    return gcd(min_num, max_num);
  }
};
