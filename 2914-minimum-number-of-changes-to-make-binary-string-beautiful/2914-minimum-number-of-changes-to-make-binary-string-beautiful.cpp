class Solution {
public:
    int minChanges(string s) {
        // Initialize with first character
        char currentChar = s[0];
        int minChangesRequired = 0, consecutiveCount = 0;
        
        // Iterate through each character
        for (const char& ch : s){
            // If current character matches the previous sequence
            if (ch == currentChar){
                ++consecutiveCount;
                continue;
            }
            
            // If we have even count of characters, start new sequence
            if (consecutiveCount % 2 == 0){
                consecutiveCount = 1;
            }
            // If odd count, we need to change current character
            else{
                consecutiveCount = 0;
                ++minChangesRequired;
            }
            
            // Update current character for next iteration
            currentChar = ch;
        }
        
        return minChangesRequired;
    }
};