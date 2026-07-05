// You are given a string s and a positive integer k.
// Return the number of substrings that contain exactly k distinct characters.
#include <bits/stdc++.h>

using namespace std;

// how many substrings have upto k distinct chars
int atMost(string s, int k) {
  // hashmap for frequency
  vector<int> freq(256, 0);
  int n = s.size();
  int distinct_count = 0, substring_count = 0;
  int left = 0;
  for (int i = 0; i < n; i++) {
    // distinct char found
    if (freq[s[i]] == 0) {
      distinct_count++;
    }
    freq[s[i]]++;
    while (distinct_count > k) {
      // increment left
      freq[s[left]]--;
      // perfect window again
      if (freq[s[left]] == 0) {
        distinct_count--;
      }
      left++;
    }
    substring_count += i - left + 1;
  }
  return substring_count;
}

void solve(string s, int k) {
  // if a string has <= k (at most k) distinct elements, then all substrings of that will have <= k distinct as well
  // same goes for k -1
  // so if i subtract atMostK - atMostK-1 => i'll be left with the exact number of substrings that have k distinct elements

  // to find number of such substrings possible -> R - L + 1 substrings

  int n = s.size();
  // finds out how many substrings have k distinct chars
  int k_count = atMost(s, k);
  int k_minus_one_count = atMost(s, k - 1);

  cout << k_count - k_minus_one_count << '\n';
}

int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  solve(s, k);
}
