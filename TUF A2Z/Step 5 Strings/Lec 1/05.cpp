// crazy 10/10 implementation - O()
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // instead of hard coding mapping and using a set 
        // understand what the isomorphic string means 

        // the last seen index of char from 's' must match the same from 't' 
        // if there is a mis match - then they're not isomofic 

        // char arrays for S and T - char has values till 255 that's it 
        vector<int> s_idx(256, -1);
        vector<int> t_idx(256, -1);
        
        int n = s.size();
        for (int i = 0; i < n; i++){
            // if the occurrence matches - update it 
            if (s_idx[s[i]] == t_idx[t[i]]){
                s_idx[s[i]] = i;
                t_idx[t[i]] = i;
            } else {
                return false;
            }
        }

        return true;
    }
};

// bad implementation
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // first length should be same 
        int n = s.size(), m = t.size(); 
        if (n != m) return false;

        // i can create a map for mapping of letters of S corresponding to t 
        // if a char exists in the mapping -> and it's corresponding mapping is not equal to the required mapping - false 
        // if char does not exist - we add the mapping 
        map<char, char> mpp;
        // i also need a set for the chars that i have created mapping for - so i can't add mapping for those chars
        set<char> st;
        for (int i = 0; i < n; i++){
            // mapping does not exist - add it 
            if (mpp.find(s[i]) == mpp.end()){
                // mapping for this char already exists 
                if (st.find(t[i]) != st.end()){
                    return false;
                }
                mpp[s[i]] = t[i];
                st.insert(t[i]);
            } else {
                // mapping does not correspond to required mapping
                if (mpp[s[i]] != t[i]){
                    return false;
                }
            }
            cout << s[i] << ' ' << t[i] << "actual: " << mpp[s[i]] << '\n';
        }

        return true;
    }
};
