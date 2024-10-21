class Solution {
private:
    int n;
    // Backtrack with pruning
    void backtrack(int start, int count, int& maxCount, const string& s, unordered_set<string>& seen){
        // Prune: If the current count plus remaining characters can't exceed maxCount, return
        if (count + n - start < maxCount)
            return;
        
        // Base case: If we reach the end of the string, update maxCount
        if (start == n){
            maxCount = max(maxCount, count);
            return;
        }
        
        // Try every possible substring starting from 'start'
        for (int end = start + 1; end <= n; ++end){
            string substr = s.substr(start, end - start);
            
            // If the substring is unique
            if (!seen.count(substr)){
                // Add the substring to the seen set
                seen.insert(substr);
                // Recursively count unique substrings from the next position 
                backtrack(end, count + 1, maxCount, s, seen);
                // Backtrack: remove the substring from the seen set
                seen.erase(substr);
            }
        }
        
    }
    
public:
    int maxUniqueSplit(string s) {
        this -> n = s.size();
        unordered_set<string> seen;
        int maxCount = 0;
        backtrack(0, 0, maxCount, s, seen);
        
        return maxCount;
    }
};