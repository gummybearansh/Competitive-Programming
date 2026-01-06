// 1673B
#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve(){
  // periodicity -> chars must repeat, and no more than one occurence of a char in a particular pattern, and it should repeat across the string
  string s; cin >> s;
  set<char> st;
  for (char c: s){
    st.insert(c);
  }

  int k = st.size();
  
  for (int i = k; i < s.size(); i++){
    // every element at index k should be equal to [i-k]
    if (s[i] != s[i-k]){
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
