// 3314. Construct the Minimum Bitwise Array I & II
#include <bits/stdc++.h>
using namespace std;

// brute -> go over all possible x | x+1 and find the smallest one that equates
// to the num O(n^2);

// even more condensed optimal:
vector<int> minArrOPTIMALLLL(vector<int> v) {
  int n = v.size();
  vector<int> ans;

  for (auto num : v) {
    cout << num << ' ';
    int res = -1, d = 1;

    // while i'm at a 1 bit
    while ((num & d) != 0) {
      // this might be the left most consecutive 1 bit that i need to flip
      res = num - d;
      d <<= 1;
    }
    ans.push_back(res);
  }
  cout << '\n';
  return ans;
}

// Optimal: O(n)
// essentially - when you're doing x | x+1 -> you're changing the right most bit
// of x to 1 x + 1 will change the right most 0 to 1 (and the 1s after that to
// 0) -> but taking or will keep the 1s after that so i basically need to find a
// number, who's right most 0 bit if i change to 1, it'll give me the v[i] even
// better -> if i take the number i want to make, and change it's left most 1
// (continuous one's after it, no 0), to a 0, then i'll get the x (OR with x + 1
// will flip this 0) the left most 1 in the continuous series of 1s from right
// of num for any v[i], find first 0 bit. flip the 1 bit to it's right. that's
// your x.

// TC: O(n)
vector<int> minArrOptimal(vector<int> &v) {
  int n = v.size();
  vector<int> ans;

  for (int i = 0; i < n; i++) { // O(n)
    if (v[i] == 2)
      ans.push_back(-1);
    else {
      // int can be 32 bit (we're looping over bits, right most = 0, then 1, 2,
      // 3)
      int j = 0;
      for (j = 0; j < 32; j++) { // O(1) constant
        // 1 << j makes a mask -> 00....01, 00..10, 00...100 like that. if &
        // with this mask is 1, we know that bit is 1
        if ((v[i] & (1 << j)) > 0)
          continue;
        // now means i found a 0, now the fun part
        int prev = j - 1;
        // make prev bit 0
        // XORing with 1 << j-1 makes the 1 into a 0
        int x = v[i] ^ (1 << (j - 1));
        ans.push_back(x);
        break;
      }
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;

  // vector<int> ans = minArrOptimal(v);
  vector<int> ans = minArrOPTIMALLLL(v);

  for (auto i : ans)
    cout << i << ' ';
}
