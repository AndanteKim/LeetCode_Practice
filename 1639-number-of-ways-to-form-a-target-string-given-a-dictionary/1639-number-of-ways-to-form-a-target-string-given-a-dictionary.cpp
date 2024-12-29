class Solution {
private:
    const int mod = 1'000'000'007;
public:

    int numWays(vector<string>& words, string target) {
        int wordLength = words[0].size(), targetLength = target.size();
        vector charFreq(wordLength, vector<int>(26, 0));
        
        // Step 1: Calculate the frequency of each character at every index in "words".
        for (const string& word : words){
            for (int j = 0; j < wordLength; ++j)
                ++charFreq[j][word[j] - 97];
        }
        
        // Step 2: Initialize two dp: prevDp and dp
        vector<long> prevDp(targetLength + 1), dp(targetLength + 1);
        
        // Base case: There is one way to form an empty target string.
        prevDp[0] = 1, dp[0] = 1;

        // Step 3: Fill the DP table
        for (int currWord = 1; currWord <= wordLength; ++currWord){
            // Copy the previous row into the current row for DP.
            dp = prevDp;
            for (int currTarget = 1; currTarget <= targetLength; ++currTarget){
                int currPos = target[currTarget - 1] - 97;
                
                // If the characters match, add the number of ways.
                dp[currTarget] = (
                    dp[currTarget] + charFreq[currWord - 1][currPos] * prevDp[currTarget - 1]
                    ) % mod;            
            }

            // Move the current row to previous row for the next iteration.
            prevDp = dp;
        }

        // Step 4: The result is in prevDp[targetLength].
        return prevDp[targetLength];
    }
};