#include <iostream>
#include <math.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int t, posCount = 0, negCount = 0;
    for (int i = 0; i < n; i++){
        cin >> t;
        t == 1 ? posCount ++ : negCount ++;
    }
    int ops = 0;
    if (negCount > posCount){
        int diff = negCount - posCount;
        if (diff % 2 == 0) ops += diff / 2;
        else ops += (diff / 2) + 1;
    }
    negCount -= ops;
    posCount += ops;
    if (negCount % 2 == 1) ops ++;
    cout << ops << '\n';
}

int main(){
    int t;
    cin >> t;
    while (t--) solve();
}
