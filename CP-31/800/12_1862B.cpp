#include <iostream>
#include <vector>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int t;
        cin >> t;
        v.push_back(t);
    }
    vector<int> ans; 
    ans.push_back(v[0]);
    for (int i = 1; i < n; i++){
        if (v[i] >= ans[ans.size()-1]) ans.push_back(v[i]);
        else {
            ans.push_back(1);
            ans.push_back(v[i]);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}
