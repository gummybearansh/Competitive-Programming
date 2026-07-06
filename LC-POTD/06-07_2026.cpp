class Solution {
public:
  int removeCoveredIntervals(vector<vector<int>> &intervals) {
    // sort based on left values - if the left value is same - sort descending on right value
    // now i iterate over the intervals from left
    // if the 'right' val of that interval is greater than the max one - we increase count - and set max_r to this guy
    sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
      // if left values are same - sort DESCENDING on right value
      // handles edge case
      if (a[0] == b[0]) {
        return a[1] > b[1];
      }
      // otherwise just normal ASCENDING sort on left value
      return a[0] < b[0];
    });

    int n = intervals.size();
    int count = 1, max_r = intervals[0][1];
    for (int i = 1; i < n; i++) {
      if (intervals[i][1] > max_r) {
        max_r = intervals[i][1];
        count++;
      }
    }
    return count;
  }
};
