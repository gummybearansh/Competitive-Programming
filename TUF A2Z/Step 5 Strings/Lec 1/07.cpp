class Solution {
public:
    bool isAnagram(string s, string t) {
        // constant sized frequency map 
        vector<int> v(26, 0);

        if (s.size() != t.size()) return false;

        int n = s.size();

        // increment frequency for 's' 
        for (int i = 0; i < n; i++){
            v[s[i] - 'a'] ++;
        }


        // decrement frequency for 't'
        for (int i = 0; i < n; i++){
            v[t[i] - 'a'] --;
        }


        // confirm all frequency 0 (cancel each other out)
        for (int i = 0; i < 26; i++){
            if (v[i] != 0){
                return false;
            }
        }

        return true;
    }
};
