#include <iostream>
#include <vector>

using namespace std;

// can just hardcode the matrix 
vector<vector<int>> v = {
    {1,1,1,1,1,1,1,1,1,1},
	{1,2,2,2,2,2,2,2,2,1},
	{1,2,3,3,3,3,3,3,2,1},
	{1,2,3,4,4,4,4,3,2,1},
	{1,2,3,4,5,5,4,3,2,1},
	{1,2,3,4,5,5,4,3,2,1},
	{1,2,3,4,4,4,4,3,2,1},
	{1,2,3,3,3,3,3,3,2,1},
	{1,2,2,2,2,2,2,2,2,1},
	{1,1,1,1,1,1,1,1,1,1}
};

void solve(){
    int ans = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            char c;
            cin >> c;
            if (c == 'X') {ans += v[1][j];}
        }
    }

    cout << ans << '\n';
}
int main(){
    int t;
    cin >> t;
    while (t--){
        // solve();
        vector<vector<char>> v;
        for (int i = 0; i < 10; i++){
            vector<char> temp;
            for (int j = 0; j < 10; j++){
                char t;
                cin >> t;
                temp.push_back(t);
            }
            v.push_back(temp);
        }

        int val = 0, row, col;
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                if (v[i][j] == 'X'){
                    i > 4 ? row = 9-i : row = i;
                    j > 4 ? col = 9-j : col = j;
                    val += min(row, col) + 1;
                }
            }
        }
        cout << val << endl;
    }
}
