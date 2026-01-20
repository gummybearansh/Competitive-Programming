#include <bits/stdc++.h>

#define ll long long

using namespace std;

void area(vector<vector<double>> &squares, double y) {
  // need to find area above and below a given y
  double areaAbove = 0, areaBelow = 0;
  for (int i = 0; i < squares.size(); i++) {
    // is the y coordinate over? then it'll have area above
    double sideAbove = 0, sideBelow = 0;
    if (squares[i][1] >= y) {
      areaAbove += squares[i][2] * squares[i][2];
    } else {
      // bottom left coordinate is below y
      // so it can have area above and below y both
      sideAbove = squares[i][1] + squares[i][2] - y;
      if (sideAbove < 0) {
        // there's nothing above
        areaBelow += squares[i][2] * squares[i][2];
      } else {
        sideBelow = squares[i][2] - sideAbove;
        areaAbove += sideAbove * squares[i][2];
        areaBelow += sideBelow * squares[i][2];
      }
    }
    // cout << sideAbove << ' ' << sideBelow << '\n';
    // cout << areaAbove << ' ' << areaBelow << '\n';
  }

  cout << areaAbove << ' ' << areaBelow << '\n';
}

int main() {
  int n;
  cin >> n;
  vector<vector<double>> squares(n, vector<double>(3));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> squares[i][j];
    }
  }

  double y = 1.6667;
  // area(squares, y);
  //

  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < 3; j++) {
  //     cout << squares[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
}



int makePairs(vector<int> &a, vector<int> &b){
  int n = a.size();

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  for (auto it: b) cout << it << ' ';

  int j = 0, pairs = 0; // b iterate
  for (int i = 0; i < n; i++){
    if (a[i] > b[j]){
      pairs++;
      j++;
    }
  }

  return pairs;
}

