class Solution {
public:
    bool canBeValid(string s, string locked) {
        // Base case
        if (s.size() == 0 || s.size() % 2)
            return false;

        stack<int> openBrackets, unlocked;

        // Iterate through the string to handle '(' and ')'
        for (int i = 0; i < s.size(); ++i){
            if (locked[i] == '0')
                unlocked.push(i);
            else if (s[i] == '(')
                openBrackets.push(i);
            else{
                if (!openBrackets.empty())
                    openBrackets.pop();
                else if (!unlocked.empty())
                    unlocked.pop();
                else
                    return false;
            }
        }

        // Match remaining open brackets and the unlocked characters
        while (!openBrackets.empty() && !unlocked.empty() && openBrackets.top() < unlocked.top()){
            openBrackets.pop();
            unlocked.pop();
        }

        return openBrackets.empty()? true : false;
    }
};