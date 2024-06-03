class Solution {
private:
    bool isMatch(int pIndex, string& pattern, int sIndex, string& s, vector<string>& symbols, unordered_set<string>& wordSet){
        // Base case: reached end of pattern
        if (pIndex == pattern.size())
            return sIndex == s.size(); // True iff also reached end of s
        
        // Get current pattern character
        char symbol = pattern[pIndex];
        
        // This symbol already has an associated word
        if (!(symbols[symbol - 97]).empty()){
            string word = symbols[symbol - 97];
            // Check if it matches s[sIndex...sIndex + word.length()]
            if (s.compare(sIndex, word.size(), word))
                return false;
            
            // If it matches, continue to match the rest
            return isMatch(pIndex + 1, pattern, sIndex + word.size(), s, symbols, wordSet);
        }
        
        // Count the number of spots the remaining symbols in the pattern take
        int filledSpots = 0;
        for (int i = pIndex + 1; i < pattern.size(); ++i){
            char p = pattern[i];
            filledSpots += symbols[p - 'a'].empty() ? 1: symbols[p - 'a'].size();
        }
        
        // This symbol doesn't have an associated word
        for (int k = sIndex + 1; k <= s.size() - filledSpots; ++k){
            string newWord = s.substr(sIndex, k - sIndex);
            if (wordSet.find(newWord) != wordSet.end())
                continue;
            
            // Create or update it
            symbols[symbol - 'a'] = newWord;
            wordSet.insert(newWord);
            
            // Continue to match the rest
            if (isMatch(pIndex + 1, pattern, k, s, symbols, wordSet))
                return true;
            
            // Backtracking
            symbols[symbol - 'a'] = "";
            wordSet.erase(newWord);
        }
        
        // No mappings were valid
        return false;
    }
    
public:
    bool wordPatternMatch(string pattern, string s) {
        vector<string> symbols(26, "");
        unordered_set<string> wordSet;
        
        return isMatch(0, pattern, 0, s, symbols, wordSet);
    }
};