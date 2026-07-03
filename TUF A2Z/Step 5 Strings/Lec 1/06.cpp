class Solution {
public:
    bool rotateString(string s, string goal) {
        // goal is just S rotated - so double of S would contain goal in it definitely 

        if (s.size() != goal.size()){
            return false;
        }

        string doubled = s + s;

        return doubled.find(goal) != string::npos;
    }
};
