#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int temp = 0, s = 0;
        for (int i = 0; i < n-1; i++){
            cin >> temp; 
            s += temp;
        }
        cout << -s << endl;
    }
}
