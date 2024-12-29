class Solution {
public:
    int numWays(vector<string>& words, string target) {
        vector dp(words[0].size(), vector<int>(target.size(), -1));
        vector charFreq(words[0].size(), vector<int>(26, 0));

        // Store the frequency of every character at every index.
        for (int i = 0; i < words.size(); ++i){
            for (int j = 0; j < words[0].size(); ++j)
                ++charFreq[j][words[i][j] - 97];
        }

        return getWords(words, target, 0, 0, dp, charFreq);
    }

private:
    int mod = 1'000'000'007;
    long getWords(vector<string>& words, string& target, int wordIndex, int targetIndex,\
     vector<vector<int>>& dp, vector<vector<int>>& charFreq){
        // Base case
        if (targetIndex == target.size()) return 1;

        // Base case 2
        if (wordIndex == words[0].size() || words[0].size() - wordIndex < target.size() - targetIndex)
            return 0;

        if (dp[wordIndex][targetIndex] != -1)
            return dp[wordIndex][targetIndex];

        long countWays = 0;
        int currPos = target[targetIndex] - 97;

        // Don't match any character of target with any word.
        countWays += getWords(words, target, wordIndex + 1, targetIndex, dp, charFreq);

        // Multiply the number of choices with getWords and add it to count.
        countWays += charFreq[wordIndex][currPos] * getWords(words, target, wordIndex + 1, targetIndex + 1, dp, charFreq);

        return dp[wordIndex][targetIndex] = countWays % mod;
     }
};