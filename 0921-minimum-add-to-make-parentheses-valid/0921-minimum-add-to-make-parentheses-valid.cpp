class Solution {
public:
    int minAddToMakeValid(string s) {
        int openBrackets = 0, minRequired = 0;

        for (const char& c : s) {
            if (c == '(') ++openBrackets;
            else {
                if (openBrackets > 0) --openBrackets;
                else ++minRequired;
            }
        }

        return minRequired + openBrackets;
    }
};