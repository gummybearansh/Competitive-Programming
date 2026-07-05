class Solution {
public:
    int romanToInt(string s) {
        // mapping using array (better than map)
        int mapping[256];
        mapping['I'] = 1;
        mapping['V'] = 5;
        mapping['X'] = 10;
        mapping['L'] = 50;
        mapping['C'] = 100;
        mapping['D'] = 500;
        mapping['M'] = 1000;


        // iterate backwards 
        // if the current element is smaller than the one to it's right - we subtract 
        // otherwise we add 
        int n = s.size();
        int ans = 0, next = 0;
        for (int i = n-1; i >= 0; i--){
            // DMA 
            int curr = mapping[s[i]]; 
            // if current is smaller than next - then we subtract
            if (curr < next){
                ans -= curr;
            } else {
                ans += curr;
            }

            next = curr;
        }

        return ans;
    }
};
