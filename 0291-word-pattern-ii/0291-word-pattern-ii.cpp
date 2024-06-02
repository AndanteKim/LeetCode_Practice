class Solution {
private:
    int lenP, lenS;
    
    bool isMatch(int pIndex, int sIndex, string& pattern, string& s, unordered_map<char, string>& symbolMap, unordered_set<string>& wordSet){
        // Base case: reached end of pattern
        if (pIndex == lenP)
            return sIndex == lenS; // True iff also reached end of s
        
        // Get current pattern character
        char symbol = pattern[pIndex];
        
        // This symbol already has an associated word
        if (symbolMap.find(symbol) != symbolMap.end()){
            string word = symbolMap[symbol];
            // Check if it matches s[sIndex...sIndex + word.length()]
            if (s.compare(sIndex, word.size(), word))
                return false;
            
            // If it matches continue to match the rest
            return isMatch(pIndex + 1, sIndex + word.size(), pattern, s, symbolMap, wordSet);
        }
        
        // This symbol doesn' exist in the map
        for (int k = sIndex + 1; k <= s.size(); ++k){
            string newWord = s.substr(sIndex, k - sIndex);
            if (wordSet.find(newWord) != wordSet.end())
                continue;
            
            // Create or update it
            symbolMap[symbol] = newWord;
            wordSet.insert(newWord);
            
            // Continue to match the rest
            if (isMatch(pIndex + 1, k, pattern, s, symbolMap, wordSet))
                return true;
            
            // Backtracking
            symbolMap.erase(symbol);
            wordSet.erase(newWord);
        }
        
        // No mapping were valid
        return false;
    }
    
public:
    bool wordPatternMatch(string pattern, string s) {
        this -> lenP = pattern.size();
        this -> lenS = s.size();
        
        unordered_map<char, string> symbolMap;
        unordered_set<string> wordSet;
        return isMatch(0, 0, pattern, s, symbolMap, wordSet);
    }
};