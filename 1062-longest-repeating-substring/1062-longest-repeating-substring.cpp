class Solution {
public:
    int longestRepeatingSubstring(string s) {
        unordered_set<string> seen;
        int start = 0, length = s.size(), maxLen = 0;
        
        while (start < length){
            int end = start;
            
            // Stop if it's not possible to find a longer
            // repeating substring
            if (end + maxLen >= length)
                return maxLen;
            
            // Generate substrings of length maxLen + 1
            string currSubstr = s.substr(end, maxLen + 1);
            
            // If a repeating substring is found,
            // increase maxLen and restart
            if (seen.find(currSubstr) != seen.end()){
                start = -1;     // Restart search for new length
                seen.clear();
                ++maxLen;
            }
            else
                seen.insert(currSubstr);
            ++start;
        }
        
        return maxLen;
    }
};