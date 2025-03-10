class Solution {
private:
    vector<int> computeLPS(string& pattern){
        int patternLength = pattern.size(), index = 1, length = 0;
        vector<int> lps(patternLength, 0);
        
        // Build the LPS array
        while (index < patternLength){
            // If characters match, increment length and set lps value
            if (pattern[index] == pattern[length]){
                ++length;
                lps[index++] = length;
            }
            // If there's a mismatch, update length using the previous LPS value
            else if (length > 0)
                length = lps[length - 1];
            // No match and length is zero
            else
                lps[index++] = 0;
        }
        
        return lps;
    }
    
    bool kmpSearch(string& pattern, string& text){
        // Precompute the LPS(Longest Prefix Suffix) array for the pattern
        vector<int> lps = computeLPS(pattern);
        int patternLength = pattern.size(), textLength = text.size();
        int patternIndex = 0, textIndex = 0;
        
        // Loop through the text to find the pattern
        while (textIndex < textLength){
            // If characters match, move both indices forward
            if (text[textIndex] == pattern[patternIndex]){
                ++textIndex;
                ++patternIndex;
                
                // If we've matched the entire pattern, return true
                if (patternIndex == patternLength) return true;
            }
            
            // If there's a mismatch after some matches, use the LPS array to skip unnecessary comparisons
            else if (patternIndex > 0){
                patternIndex = lps[patternIndex - 1];
            }
            // If no matches, move to the next character in text
            else{
                ++textIndex;
            }
        }
        
        // Pattern not found in text
        return false;
    }
    
public:
    bool rotateString(string s, string goal) {
        // Check if the lengths of the both strings are different; if so, they can't be rotations.
        if (s.size() != goal.size()) return false;
        
        // Concatenate 's' with itself to create a new string containing all possible rotations
        string doubleString = s + s;
        
        // Perform KMP substring search to check if 'goal' is a substring of 'double_string'
        return kmpSearch(goal, doubleString);
    }
};