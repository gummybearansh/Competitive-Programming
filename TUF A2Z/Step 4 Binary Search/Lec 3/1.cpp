// Find row with maximum 1s
// in a binary 2d matrix, where each row is sorted, find the row with maximum 1s
#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

void solve_best(vector<vector<int>> &v) {
  // staircase solution - O(n + m)
  // if in a row i find a 1, now the next row i'll look will definitely need to have a 1 before that
  int n = v.size();
  int m = v[0].size();

  int max_row_idx = -1;
  int i = 0;     // top row
  int j = m - 1; // last column

  // till valid cell
  while (i < n && j >= 0) {
    if (v[i][j] == 1) {
      // try finding a 1 column in this row before current
      max_row_idx = i;
      j--;
    } else {
      // found a 0, try the next row now
      i++;
    }
  }
  cout << "row with max count " << max_row_idx << '\n';
}

int count_ones(vector<int> &v) {
  int n = v.size();
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (v[mid] == 1)
      high = mid - 1;
    else
      low = mid + 1;
  }
  return n - low;
}

void solve(vector<vector<int>> &v) {
  // count the 1s in each row O(n * m)

  // use BS to find the 1st 1 in each row, and then compute the number of 1s in that row (it's sorted) O(n * log(m))
  int n = v.size(), m = v[0].size();

  int max_one_count = 0;
  for (int i = 0; i < n; i++) {
    // now for this row (v[i])
    int one_count = count_ones(v[i]);
    if (one_count > max_one_count) {
      max_one_count = one_count;
    }
  }

  cout << max_one_count << '\n';
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> v(n, vector<int>(m));

  for (auto &row : v) {
    for (auto &col : row) {
      cin >> col;
    }
  }

  solve_best(v);

  for (auto r : v) {
    for (auto c : r) {
      cout << c << ' ';
    }
    cout << '\n';
  }
}
