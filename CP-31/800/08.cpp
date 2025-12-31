#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        vector<int> v(n, 0);
        // just need to check if k exists in the array
        // if it does then in that subarray - of size 1
        // k is the most frequent element of that subarray
        bool found = false;
        for (int i = 0; i < n; i++){
            cin >> v[i];
            if (v[i] == k){
                found = true;
            }
        }
        if (!found) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}
