// 1842B
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<ll> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }

  // need to make X by taking OR of knowledge with book at the top of the stack
  // ORDER DOESN'T MATTER -> i can do 1 book from a, 1 from b, 1 from c -> Since
  // they're getting ORRED, i can do it one stack at a time, no difference
  // important is when to take a book
  // i need to eventually keep OR'ring till i Reach X
  // if i find a book, and it has 1 in bits that X has 0, then i can't take that
  // book, i can never reverse a 1 once ive' orred it. the way to check -> if
  // (book | x == x) => meaning it should have 1s in exactly the places that x
  // has them. and if it does, then it'll result in x wow wowowoowwowowoo
  ll k = 0;
  for (int i = 0; i < n; i++) {
    if ((a[i] | x) == x) {
      k = (k | a[i]);
    } else {
      // can't take any book from this stack
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if ((b[i] | x) == x) {
      k = (k | b[i]);
    } else {
      // can't take any book from this stack
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if ((c[i] | x) == x) {
      k = (k | c[i]);
    } else {
      // can't take any book from this stack
      break;
    }
  }

  k == x ? cout << "YES\n" : cout << "NO\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
