// Search in a 2D matrix
// each row is sorted and first element of each row is greater than last element of previous row
#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

// same optimal O(log(n * m)) = O(log n + log m)
bool searchMatrix(vector<vector<int>> &matrix, int target) {
  int n = matrix.size();
  int m = matrix[0].size();

  int low = 0, high = n * m - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;

    // good math
    int row = mid / m;
    int col = mid % m;

    if (matrix[row][col] == target) {
      return true;
    } else if (matrix[row][col] > target) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return false;
}

bool find_target_in_row(vector<int> v, int target) {
  int n = v.size();
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (v[mid] == target) {
      return true;
    } else if (v[mid] > target) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return false;
}

// O(log(n) + log(m))
void solve(vector<vector<int>> v, int target) {
  // i can binary search each row - basically a BS 0 - n
  // where i check the first and last element of each row
  // the correct row will have first_element <= target <= last_element
  // and then i can binary search the correct row
  int n = v.size();
  int m = v[0].size();

  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    // if this is the valid row
    if (v[mid][0] <= target && v[mid][m - 1] >= target) {
      if (find_target_in_row(v[mid], target)) {
        cout << "Yes target found at " << mid << " row \n";
        return;
      }
      // if strictly sorted - only this row can possibly have the answer - no point looking for more
      break;
    }

    // too big, go back
    else if (v[mid][0] > target) {
      high = mid - 1;
    }
    // too small, go up
    else {
      low = mid + 1;
    }
  }
  // could not return before
  cout << "No, could not find target\n";
}

int main() {
  int n, m, target;
  cin >> n >> m >> target;
  vector<vector<int>> v(n, vector<int>(m));
  for (auto &row : v) {
    for (auto &col : row) {
      cin >> col;
    }
  }

  for (auto r : v) {
    for (auto c : r) {
      cout << c << ' ';
    }
    cout << '\n';
  }

  solve(v, target);
}
