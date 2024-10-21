class Solution {
private:
    int n;
    int backtrack(int start, const string& s, unordered_set<string>& seen){
        // Base case: If we reach the end of the string, return 0 (no more
        // substrings to add)
        if (start == n) return 0;
        
        int maxCount = 0;
        
        // Try every possible substring starting from 'start'
        for (int end = start + 1; end <= n; ++end){
            string subStr = s.substr(start, end - start);
            
            // If the substring is unique
            if (!seen.count(subStr)){
                // Add the substring to the seen set
                seen.insert(subStr);
                // Recursively count unique substrings from the next position
                maxCount = max(maxCount, 1 + backtrack(end, s, seen));
                // Backtrack: remove the substring from the seen set
                seen.erase(subStr);
            }
        }
        
        return maxCount;
    }
    
public:
    int maxUniqueSplit(string s) {
        this -> n = s.size();
        unordered_set<string> seen;
        return backtrack(0, s, seen);
    }
};