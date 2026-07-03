// bucket sort implementation - TC: O(N) + extra O(N) space
class Solution {
public:
  string frequencySort(string s) {
    // create a frequency array - 256 sized - count the frequency of each of the letters

    // O(N) - counting the frequencies
    vector<int> freq(256, 0);
    int n = s.size();
    for (int i = 0; i < n; i++) {
      freq[s[i]]++;
    }

    // O(N) space - the buckets
    // buckets[i] will hold all chars having 'i' frequency
    vector<vector<char>> buckets(n + 1);

    // O(1) populate the buckets
    for (int i = 0; i < 256; i++) {
      if (freq[i] > 0) {
        buckets[freq[i]].push_back(char(i));
      }
    }

    // O(N) - reconstruct the string
    string ans = "";
    ans.reserve(n);

    // iterate backwards - max freq to 1
    for (int i = n; i > 0; i--) {
      // there might be multiple chars with same frequency
      for (char c : buckets[i]) {
        // count, char
        ans.append(i, c);
      }
    }

    return ans;
  }
};

// normal sort implementation - TC: O(N), SC: O(1)
class Solution {
public:
  string frequencySort(string s) {
    // create a frequency array - 256 sized - count the frequency of each of the letters

    vector<int> freq(256, 0);

    int n = s.size();
    for (int i = 0; i < n; i++) {
      freq[s[i]]++;
    }

    // now can create an array of pairs to sort
    vector<pair<int, char>> v_p;
    for (int i = 0; i < 256; i++) {
      if (freq[i] == 0) {
        continue;
      }
      v_p.push_back({freq[i], char(i)});
    }

    sort(v_p.rbegin(), v_p.rend());

    // now create the final string (just a vector of chars)
    string ans = "";
    // pre allocates capacity - size remains 0
    ans.reserve(n);
    for (auto p : v_p) {
      // writes char p.first time instantly - block write
      ans.append(p.first, p.second);
    }

    return ans;
  }
};
