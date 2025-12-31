#include <iostream>
#include <vector> 
#include <algorithm> 
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    // if all elements are equal -> not possible 
    if (v[0] == v[n-1]){
        cout << -1 << endl;
        return;
    }
    // otherwise, b -> all instances of the smallest number 
    // c -> all other numbers 
    // if Cj > Bi -> c elements cannot be divisor of b elements 
    vector<int> b, c;
    b.push_back(v[0]);
    for (int i = 1; i < n; i++){
        if (v[i] == b[0]) b.push_back(v[i]); 
        else c.push_back(v[i]);
    }
    cout << b.size() << ' ' << c.size() << endl;
    for (int i = 0; i < b.size(); i++) cout << b[i] << ' ';
    cout << endl;
    for (int i = 0; i < c.size(); i++) cout << c[i] << ' ';
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--){solve();}
}
