class Solution {
public:
    bool wordPatternMatch(string pattern, string s) {
        unordered_map<char, string> mapping;
        unordered_set<string> wordSet;
        function<bool(int, int)> isMatch = [&](int pIdx, int sIdx){
            // Base case
            if (pIdx == pattern.size()) return sIdx == s.size();

            char symbol = pattern[pIdx];
            if (mapping.contains(symbol)) {
                string word = mapping[symbol];
                if (s.substr(sIdx, word.size()) != word) return false;

                return isMatch(pIdx + 1, sIdx + word.size());
            }

            for (int k = sIdx + 1; k <= s.size(); ++k) {
                string newWord = s.substr(sIdx, k - sIdx);
                
                if (wordSet.contains(newWord)) continue;
                mapping[pattern[pIdx]] = newWord;
                wordSet.insert(newWord);
                if (isMatch(pIdx + 1, sIdx + newWord.size())) return true;
                mapping.erase(pattern[pIdx]);
                wordSet.erase(newWord);
            }

            return false;
        };

        return isMatch(0, 0);
    }
};