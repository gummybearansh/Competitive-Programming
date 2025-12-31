#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int temp, ans = INT_MAX;
    for (int i = 0; i < n; i++){
        cin >> temp;
        temp < 0 ? temp = -temp : temp = temp;
        ans = min(ans, temp); 
    }
    cout << ans << endl;
}

