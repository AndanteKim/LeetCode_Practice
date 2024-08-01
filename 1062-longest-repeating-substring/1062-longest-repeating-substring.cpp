class Solution {
public:
    int longestRepeatingSubstring(string s) {
        unordered_set<string> seen;
        int length = s.size() - 1;
        
        for (int maxLen = length; maxLen >= 0; --maxLen){
            seen.clear();
            for (int start = 0; start <= s.size() - maxLen; ++start){
                int end = start;
                // Extract substring of length maxLen
                string currSubstr = s.substr(end, maxLen);
                
                // If the substring is already in the set,
                // it means we've found a repeating substring
                if (seen.count(currSubstr)) return maxLen;
                
                seen.insert(currSubstr);
            }
        }
        
        return 0;
    }
};