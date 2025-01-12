class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();

        // Base case: If the length of s is odd or empty, then return false.
        if (n == 0 || n % 2)
            return false;

        int openBrackets = 0, unlocked = 0;
        // Iterate through the string to handle '(' and ')'
        for (int i = 0; i < n; ++i){
            if (locked[i] == '0')
                ++unlocked;
            else if (s[i] == '(')
                ++openBrackets;
            else{
                if (openBrackets > 0)
                    --openBrackets;
                else if (unlocked > 0)
                    --unlocked;
                else
                    return false;
            }
        }

        // Match remaining open brackets with unlocked characters.
        int balance = 0;
        for (int i = n - 1; i >= 0; --i){
            if (locked[i] == '0'){
                --balance;
                --unlocked;
            }
            else if (s[i] == '('){
                ++balance;
                --openBrackets;
            }
            else if (s[i] == ')'){
                --balance;
            }

            if (balance > 0)
                return false;

            if ((unlocked == 0) && (openBrackets == 0))
                break;
        }

        return openBrackets > 0? false : true;
    }
};