#include <iostream>
#include <vector>

#define ll long long;

using namespace std;

// PATTERN - Run Length Encoding (RLE) -> reducing 'ssuusssssuu' to [{'s', 2}, {'u', 2}, {'s', 3}, {'u', 2}]
void upsolving() {
  // the closest 's' to every 'u' needs to be equal characters away
  // meaning needs to be one on the left and one on the right 'sXXuXXs'
  // but, if there is even two consecutive 'uu' -> 'suus' -> this condition
  // cannot be satisfied so a valid suspicious string would not have consecutive
  // 'u's -> make alternating 'u's in a block of u s
  //    ex: 'suuus' 3'u' -> 1 converted: 'susus'or "suuuus" 4'u' -> 2 converted
  //    "sususs" convert floor(number of continuous Us) / 2
  string s;
  cin >> s;
  // first and last must be S
  int ans = 0;
  if (s[0] == 'u') {
    ans++;
    s[0] = 's';
  }
  if (s.back() == 'u') {
    ans++;
    s.back() = 's';
  }

  // very smart way to convert the string into a vector that says [{element,
  // freq_in_block}, {element, f..}] make a vector of pairs, with 1 element
  // initially -> set to {s, 1}
  vector<pair<char, int>> v(1, {'s', 1});
  for (int i = 0; i < s.size(); i++) {
    // if the current char of s is the same as the last character recorded,
    // increase it's frequency
    if (s[i] == v.back().first)
      v.back().second++;
    // otherwise add the new char, with 'block' frequency 1
    else
      v.push_back({s[i], 1});
  }

  // since v[0] is for 's' block, then idx 1, 3, 5 will be blocks of u -> SO
  // FUCKING SMART
  for (int i = 1; i < v.size(); i += 2) {
    ans += v[i].second / 2;
  }

  cout << ans << '\n';
}

void solve() {
  string s;
  cin >> s;

  int n = s.size();
  int ans = 0;
  if (s[0] == 'u') {
    s[0] = 's';
    ans++;
  }
  if (s[n - 1] == 'u') {
    s[n - 1] = 's';
    ans++;
  }

  // cout << s << ' ' << ans << '\n';
  for (int i = 1; i < n - 1; i++) {
    if (s[i] == 'u') {
      // go left and right and compare
      int l = i - 1, r = i + 1;
      while (l >= 0 && r < n) {
        // cout << s << ' ' << ans << '\n';
        if (s[l] == 's' && s[r] == 's') {
          break;
        } else if (s[r] != 's') {
          s[r] = 's';
          ans++;
          break;
        } else if (s[l] != 's') {
          s[l] = 's';
          ans++;
          break;
        }
        l--;
        r++;
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    upsolving();
  }
}
