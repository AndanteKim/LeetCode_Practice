class Solution {
public:
    int minAddToMakeValid(string s) {
        int openBrackets = 0, minAddsRequired = 0;
        
        for (const auto& c : s){
            if (c == '(')
                ++openBrackets;
            else{
                // If open bracket exists, match it with the closing one
                // If not, we need to add a open bracket.
                openBrackets > 0? --openBrackets : ++minAddsRequired;
            }
        }
        
        // Add the remaining open brackets as closing brackets would be required.
        return minAddsRequired + openBrackets;
    }
};