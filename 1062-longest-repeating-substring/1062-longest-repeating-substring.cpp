class Solution {
private:
    bool hasRepeatingSubstr(string& s, int length){
        unordered_set<string> seen;
        for (int i = 0; i <= s.size() - length; ++i){
            // Extract a substring of the given length
            string subStr = s.substr(i, length);
            
            // Check if the substring has been seen before
            if (seen.count(subStr))
                return true;
            
            seen.insert(subStr);
        }
        
        return false;
    }
    
public:
    int longestRepeatingSubstring(string s) {
        int start = 1, end = s.size() - 1;
        
        while (start <= end){
            int mid = (start + end) >> 1;
            
            // Check if there's a repeating substring of length mid
            if (hasRepeatingSubstr(s, mid))
                start = mid + 1;    // Try longer substrings
            else
                end = mid - 1;      // Try shorter substrings
        }
        
        return start - 1;
    }
};