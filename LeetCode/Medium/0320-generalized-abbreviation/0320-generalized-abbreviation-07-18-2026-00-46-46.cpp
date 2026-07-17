class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        int n = word.size();
        vector<string> ans;

        for (int mask = 0; mask < (1 << n); ++mask) {
            string currWord = "";
            int abbrCnt = 0;

            for (int i = 0; i < n; ++i) {
                // If the bit at the position index is 1, increment the abbreviated substring.
                if (mask & (1 << i)) ++abbrCnt;
                else {
                    // Append the last substring and then the current character.
                    if (abbrCnt > 0) {
                        currWord += to_string(abbrCnt);
                        abbrCnt = 0;
                    }
                    currWord.push_back(word[i]);
                }
            }

            if (abbrCnt > 0) currWord += to_string(abbrCnt); 
            ans.push_back(currWord);
        }

        return ans;
    }
};