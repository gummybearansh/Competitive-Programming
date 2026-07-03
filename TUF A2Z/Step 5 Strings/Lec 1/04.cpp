// SOLUTION 1 - O(N * M)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // consider the first word to be the prefix 
        // iterate over the remaining words trying to find the common portion from our prefix 
        int n = strs.size();
        string pref = strs[0];
        for (int i = 1; i < n; i++){ // O(n)
            int j = 0;
            // check character by character for common portion
            while (j < pref.size() && j < strs[i].size() && pref[j] == strs[i][j]){ // O(m)
                j++;
            }
            
            // now pref should only contain upto J index 
            // erases from jth index to the end
            pref.erase(j); // O(M)

            // no common prefix found
            if (pref == ""){
                return "";
            }
        }
        return pref;
    }
};

// SOLUTION 2 - O(n * log n * m)
// > It's not + beacuse the M multiplication is not coming from going through the first and last string
// it's coming from the sorting itself 
// strings can't be directly compared using < or > - the N log N sorting relies on this - for strings we'll have to do M operations to compare - so the complexity becomes M * N Log N for sorting itself and then a + M to go through the string once character by character wowowowowo
// - `Time Complexity:` O(N * LOG (M) * M) - sorting the entire string array in N LOG N and then having to go through 
// - `Space Complexity:` O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // can sort the strings lexicographically 
        // now the first and last string would be the most different and if i can find the common portion between these - i have the common prefix 

        sort(strs.begin(), strs.end());

        int n = strs.size();
        int min_length = min(strs[0].size(), strs[n-1].size());
        int i;
        for (i = 0; i < min_length; i++){
            if (strs[0][i] != strs[n-1][i]){
                // this is the common prefix - break here
                break;
            }
        }
        // the entire short string might be too so we return here 
        return strs[0].substr(0, i);
    }
};

