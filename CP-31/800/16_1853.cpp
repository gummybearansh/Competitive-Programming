#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        int t;
        cin >> t;
        v[i] = t;
    }
    // finding min dif 
    int minDif = INT_MAX;
    bool sorted = true;
    for (int i = 1; i < n; i++){
        if (v[i] < v[i-1]){
            sorted = false;
            break; 
        }
        minDif = min(minDif, v[i]-v[i-1]);
    }

    if (!sorted) cout << 0 << endl;
    else {
        // if (minDif % 2 == 0) cout << minDif/2 << endl;
        // else cout << (minDif/2) + 1 << endl;
        cout << (minDif/2) + 1 << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){solve();}
}
