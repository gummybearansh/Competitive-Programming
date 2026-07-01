// Search in 2D Matrix II
#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

// O(n + m) (worst case moving corner to corner)
// basically found that row + respective col is sorted - so i can eliminate halves 
void solve_optimal(vector<vector<int>> &matrix, int target) {
  int n = matrix.size();
  int m = matrix[0].size();

  // start at top right cell
  int row = 0, col = m - 1;

  // valid cell
  while (row < n && col >= 0) {
    if (matrix[row][col] == target) {
      cout << "Target found at " << row << ' ' << col << '\n';
      return;
    }
    // if the current number is smaller than target, then just move to the next row (we start from top right) 
    else if (matrix[row][col] < target) {
      row++;
    } else {
      // current number is too big -> move one column left
      col--;
    }
  }
  cout << "Target not found";
}

int bin_search(vector<int> &v, int target) {
  int n = v.size();
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (v[mid] == target) {
      return mid;
    } else if (v[mid] > target) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}

// O(n * log(m))
// going over each row and performing binary search on that row
void solve_1(vector<vector<int>> &matrix, int target) {
  int n = matrix.size();
  int m = matrix[0].size();

  for (int i = 0; i < n; i++) {
    // matrix[i] is the row to perform binary search on
    int col_idx = bin_search(matrix[i], target);
    if (col_idx != -1) {
      cout << "Target found at " << i << " row and " << col_idx << " col" << '\n';
      return;
    }
  }
  cout << "Target not found\n";
}

int main() {
  int n, m, target;
  cin >> n >> m >> target;
  vector<vector<int>> v(n, vector<int>(m));

  for (auto &r : v)
    for (auto &c : r)
      cin >> c;

  // solve_1(v, target);
  solve_optimal(v, target);
}
