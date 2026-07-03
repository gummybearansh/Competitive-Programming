
class Solution {
public:
    string largestOddNumber(string num) {
        // the string will guaranteed be a number 
        // i can just iterate from the end 
        // find the first odd number index i find 
        // and i'll return the num upto that index 
        int n = num.size();

        int idx = -1;
        for (int i = n-1; i >= 0; i--){
            // converting numerical string to integer
            if ((num[i] - '0') % 2 == 1){
                idx = i;
                break;
            }
        }
        // didn't find any odd number
        if (idx == -1){
            return "";
        }
        // needs char count - which would be idx + 1
        return num.substr(0, idx + 1);
    }
};
