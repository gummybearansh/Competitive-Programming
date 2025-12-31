#include <iostream>
using namespace std;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    if (c%2 == 1) b--;
    if (a > b) cout << "First\n";
    else cout << "Second\n";
}

int main(){
    int t; 
    cin >> t;
    while (t--){
        solve();
    }
}
