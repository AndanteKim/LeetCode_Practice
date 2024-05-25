class Solution {
private:
    int n;
    void backtrack(const string& s, const unordered_set<string>& wordSet, string& curr, vector<string>& ans, int start){
        // If we've reached the end of the string, add the current sentence to ans
        if (start == n){
            ans.push_back(curr);
            return;
        }
        
        // Iterate over possible end indices
        for (int end = start + 1; end <= n; ++end){
            string word = s.substr(start, end - start);
            
            // If the word is in the set, proceed with backtracking
            if (wordSet.find(word) != wordSet.end()){
                string original = curr;
                if (!curr.empty()) curr += " ";
                curr += word;
                // Recursively call backtrack with the new end index
                backtrack(s, wordSet, curr, ans, end);
                curr = original;
            }
        }
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Convert wordDict to a set for O(1) lookups
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        this -> n = s.size();
        vector<string> ans;
        string curr;
        
        // Start the backtracking process
        backtrack(s, wordSet, curr, ans, 0);
        
        return ans;
    }
};