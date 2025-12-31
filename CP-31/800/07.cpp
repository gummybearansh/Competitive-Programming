#include <iostream>
#include <string>
using namespace std;

bool check(string s, string x){
   if (x.size() < s.size()) return false;
   
   for (int i = 0; i < x.size() - s.size() + 1; i++){
        if (x.substr(i, s.size()) == s) return true;
   }
   return false;
}

int main(){
    int t;
    cin >> t;
    
    while (t--){
        // inputs
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x >> s;
        
        string x0 = x;
        string x1 = x0 + x0; // 1 op
        string x2 = x1 + x1; // 2 op
        string x3 = x2 + x2; // 3 op
        string x4 = x3 + x3; // 4 op
        string x5 = x4 + x4; // 5 ops (max -> x5.size() = 2^32) 

        long long ans = -1;
        if (check(s, x0)) ans = 0;
        else if (check(s, x1)) ans = 1;
        else if (check(s, x2)) ans = 2;
        else if (check(s, x3)) ans = 3;
        else if (check(s, x4)) ans = 4;
        else if (check(s, x5)) ans = 5;
        cout << ans << endl;
    }
    return 0;
}
