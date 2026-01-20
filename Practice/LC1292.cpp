// prefix sum of a matrix basically
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> prefixSum(vector<vector<int>> &mat) {
  int n = mat.size();
  int m = mat[0].size();

  vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pref[i][j] = mat[i - 1][j - 1] + pref[i - 1][j] + pref[i][j - 1] -
                   pref[i - 1][j - 1];
    }
  }
  // for (int i = 0; i <= n; i++) {
  //   for (int j = 0; j <= m; j++) {
  //     cout << pref[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
  return pref;
}

bool check(int size, vector<vector<int>> &mat, int threshold,
           vector<vector<int>> &pref) {
  // k is offset
  int k = size - 1;
  int n = mat.size();
  int m = mat[0].size();
  for (int i = 0; i < n - k; i++) {
    for (int j = 0; j < m - k; j++) {
      // check if it's possible to make a valid square with the given offset
      int r2 = i + k;
      int c2 = j + k;
      // in the normal method we had a check to make sure the square will be
      // constructed of valid size (offset se), instead of that make sure to
      // adjust the index of the loop
      int sum =
          pref[r2 + 1][c2 + 1] - pref[i][c2 + 1] - pref[r2 + 1][j] + pref[i][j];
      if (sum <= threshold) {
        return true;
      }
    }
  }
  return false;
}

int maxSideLengthOptimal(vector<vector<int>> &mat, int threshold) {
  // instead of linearly iterating over the side length, try to do a binary
  // search on side length
  int n = mat.size();
  int m = mat[0].size();

  vector<vector<int>> pref = prefixSum(mat);

  int low = 0, high = min(m, n);
  int ans = 0;
  while (low <= high) {
    int mid = low + (high - low) / 2;

    // returns true if it's valid to create one of this size
    if (check(mid, mat, threshold, pref)) {
      // if its possible to create one of this size, try to make one with bigger
      ans = mid;
      low = mid + 1;
    } else {
      // size is already too big, try smaller
      high = mid - 1;
    }
  }
  return ans;
}

int maxSideLengthBrute(vector<vector<int>> &mat, int threshold) {
  int n = mat.size();
  int m = mat[0].size();

  vector<vector<int>> pref = prefixSum(mat);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // at each element try to find the square of side (1, 2, 3 ,..)
      // k is offset -> to find a square we need two points, (opposite
      // diagnoals) side will be this offset + 1
      for (int k = 0; k < min(n - i, m - j); k++) {
        int r2 = i + k;
        int c2 = j + k;
        int sum = pref[r2 + 1][c2 + 1] - pref[i][c2 + 1] - pref[r2 + 1][j] +
                  pref[i][j];
        if (sum <= threshold) {
          ans = max(ans, k + 1);
        } else {
          // if it's not possible to create square of this size, then no point
          // of making a bigger one
          break;
        }
      }
    }
  }

  return ans;
}

int main() {
  int n, m, threshold;
  cin >> n >> m >> threshold;

  vector<vector<int>> mat(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
  }
  cout << maxSideLengthOptimal(mat, threshold);
}
