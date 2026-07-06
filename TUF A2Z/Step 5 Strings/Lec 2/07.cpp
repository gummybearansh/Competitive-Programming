class Solution {
public:
  // returns beauty of current frequency array
  int mx_mn(vector<int> & v) { // O(256)
    int mn = INT_MAX, mx = -1;
    for (int i = 0; i < v.size(); i++) {
      if (v[i] != 0) {
        mn = min(mn, v[i]);
        mx = max(mx, v[i]);
      }
    }
    // if no other minimum was found
    return mn == INT_MAX ? 0 : mx - mn;
  }

  int ans = 0;
  int beautySum(string s) {
    // frequency map for alphabets
    // iterate over all substrings - O(n^2)
    // traverse frequency map for lowest and highest frequency char - O(256)
    int n = s.size();
    for (int i = 0; i < n; i++) { // O(N^2)
      vector<int> freq(256, 0);
      for (int j = i; j < n; j++) {
        freq[s[j]]++;
        ans += mx_mn(freq);
      }
    }
    return ans;
  }
};
