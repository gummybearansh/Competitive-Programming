#include <bits/stdc++.h>

#define ll long long

using namespace std;

// previous number parity?
// next number = parity
// next parity diff => index 1 based indexing

// 1011
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> even, odd;

  for (int i = 1; i <= n; i++) {
    int num;
    cin >> num;
    if (num % 2 == 0)
      even.push_back(i);
    else
      odd.push_back(i);
  }

  if (even.size() == 1)
    cout << even[0];
  else
    cout << odd[0];
  return 0;
}
