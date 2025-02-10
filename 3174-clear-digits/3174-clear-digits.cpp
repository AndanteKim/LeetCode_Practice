class Solution {
public:
    string clearDigits(string s) {
        string ans = "";

        // Iterate over each character in the input string
        for (int charIndex = 0; charIndex < s.size(); ++charIndex){
            // If the current character is a digit
            if (isdigit(s[charIndex]) && !ans.empty())
                // If the answer string isn't empty, remove the last character
                ans.pop_back();
            else
                // If the character is not a digi, add it to the answer string
                ans.push_back(s[charIndex]);
        }

        return ans;
    }
};