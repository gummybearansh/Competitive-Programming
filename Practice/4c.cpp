#include <iostream>
#include <map>

using namespace std;

// pretty interesting implementation of hashing + storing num
// didint click without solution - brute was easy with set - needed tot ake one step further
// playing with char and strings is a nightmare 
void solve() {
  int n;
  cin >> n;

  // string, count
  map<string, int> mpp;
  while (n--) {
    string s;
    cin >> s;
    if (mpp.find(s) != mpp.end()) {
      // if found -> add 1 to count and print s with count
      mpp[s] += 1;
      cout << s << mpp[s] << "\n";
    } else {
      // if not found - print ok and add it to map with count 0
      cout << "OK\n";
      mpp.insert({s, 0});
    }
  }
}

int main() { solve(); }
