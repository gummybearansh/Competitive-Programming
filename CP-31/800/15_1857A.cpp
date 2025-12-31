#include <iostream>
#include <vector>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    int oddCount = 0;
    for (int i = 0; i < n; i++){
        int t; 
        cin >> t;
        if (t % 2 == 1) oddCount++;
    }
    // logic :- if no. of odd is odd -> not possible to make two equal parity sums 
    if (oddCount % 2 == 1) cout << "NO\n";
    else cout << "YES\n";
}

int main(){
    int t; 
    cin >> t;
    while (t--){
        solve();
    }
}
