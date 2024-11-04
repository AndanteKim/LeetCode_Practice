class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        
        // pos tracks our position in the input string
        int pos = 0, n = word.size();
        
        // Process until we reach end of string
        while (pos < n){
            char currentChar = word[pos];
            int consecutiveCount = 0;
            
            // Count consecutive occurrences (maximum 9)
            while (pos < n && consecutiveCount < 9 && currentChar == word[pos]){
                ++consecutiveCount;
                ++pos;
            }
            
            // Append count followed by character to result
            ans += to_string(consecutiveCount) + currentChar;
        }
        return ans;
    }
};