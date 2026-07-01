// find peak element II
class Solution {
public:
  int find_max_element(vector<vector<int>> &mat, int col) {
    int n = mat.size();
    int max_element = INT_MIN;
    int row_idx = -1;
    for (int i = 0; i < n; i++) {
      if (mat[i][col] > max_element) {
        max_element = mat[i][col];
        row_idx = i;
      }
    }
    return row_idx;
  }

  vector<int> findPeakGrid(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();

    // edge case where there's only 1 column
    if (m == 1) {
      int row_idx = find_max_element(mat, 0);
      return {row_idx, 0};
    }
    int low = 0, high = m - 1;
    while (low <= high) {
      // choose the mid column (BS on cols)
      int mid = low + (high - low) / 2;

      // find the max element of this column
      int row_idx = find_max_element(mat, mid);
      int col_idx = mid;

      // slight optimisation
      // treat out of bounds as -1 : now handles the edge case as well

      int left_val = (mid - 1 >= 0) ? mat[row_idx][mid - 1] : -1;
      int right_val = (mid + 1 < n) ? mat[row_idx][mid + 1] : -1;
      // now mat[row_idx][col_idx] is our potential peak
      // i don't need to check against row_idx - they'll always be greater than the rest - it's the max element of that column
      if (col_idx == 0) {
        // check right
        if (mat[row_idx][col_idx] > mat[row_idx][col_idx + 1]) {
          return {row_idx, col_idx};
        } else {
          low = mid + 1;
        }
      } else if (col_idx == m - 1) {
        // check left
        if (mat[row_idx][col_idx] > mat[row_idx][col_idx - 1]) {
          return {row_idx, col_idx};
        } else {
          high = mid - 1;
        }
      } else {
        // check left and right
        // if smaller than right - look in the right
        if (mat[row_idx][col_idx] < mat[row_idx][col_idx + 1]) {
          low = mid + 1;
        } else if (mat[row_idx][col_idx] < mat[row_idx][col_idx - 1]) {
          // smaller than left - look in left
          high = mid - 1;
        } else {
          return {row_idx, col_idx};
        }
      }
    }
    return {-1, -1};
  }
};
