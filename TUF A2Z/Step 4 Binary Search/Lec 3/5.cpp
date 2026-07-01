// find matrix median
// given a 2D matrix with odd rows and cols - which is row wise sorted

#include <bits/stdc++.h>

#define ll long long
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;

// finds upperbound of target in array (index of first element greater than target)
int ub(vector<int> &v, int target) {
  int low = 0, high = v.size() - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (v[mid] <= target)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low;
}

// finds the number of elements smaller or equal to target in entire matrix
int black_box(vector<vector<int>> &v, int target) {
  int n = v.size(), m = v[0].size();

  int count = 0;
  for (int i = 0; i < n; i++) {
    // finds upper bound of this row
    count += ub(v[i], target);
  }
  return count;
}

int find_median(vector<vector<int>> &v) {
  // search space
  int n = v.size(), m = v[0].size();
  int target_count = (n * m) / 2;

  int low = v[0][0], high = v[n-1][m-1];
  while (low <= high) {
    int mid = low + (high - low) / 2;

    // finds the number of elements smaller and equal to the target
    int count = black_box(v, mid);

    if (count <= target_count)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat(n, vector<int>(m));

  for (auto &r : mat) {
    for (auto &c : r) {
      cin >> c;
    }
  }

  cout << find_median(mat);

  for (auto r : mat) {
    for (auto c : r) {
      cout << c << ' ';
    }
    cout << '\n';
  }
}
