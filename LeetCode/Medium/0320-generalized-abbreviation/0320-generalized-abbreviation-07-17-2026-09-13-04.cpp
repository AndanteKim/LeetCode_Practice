class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        int n = word.size();
        vector<string> ans;
        
        auto backtrack = [&] (auto&& self, string currWord, int i, int abbreviateCount) -> void {
            if (i == n) {
                if (abbreviateCount > 0) currWord += to_string(abbreviateCount);
                ans.push_back(currWord);
                return;
            }

            // Keep the current characters
            self(self, currWord + (abbreviateCount > 0? to_string(abbreviateCount) : "") + word[i], i + 1, 0);

            // Abbreviate the current characters
            self(self, currWord, i + 1, abbreviateCount + 1);
        };
        
        backtrack(backtrack, "", 0, 0);

        return ans;
    }
};