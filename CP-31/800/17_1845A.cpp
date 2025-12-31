#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    if (x != 1) {
        cout << "YES\n";
        cout << n << '\n';
        for (int i = 0; i < n; i++) {
            cout << 1 << ' ';
        }
        cout << '\n';
    } else {
        if (k == 1) {
            cout << "NO\n";
        } else if (k == 2 && n % 2 == 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            vector<int> ans;
            while (n > 0) {
                if (n % 2 == 0) {
                    ans.push_back(2);
                    n -= 2;
                } else {
                    ans.push_back(3);
                    n -= 3;
                }
                if (n < 0) {
                    cout << "NO\n";
                    return;
                }
            }
            cout << ans.size() << '\n';
            for (int val : ans) {
                cout << val << ' ';
            }
            cout << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
