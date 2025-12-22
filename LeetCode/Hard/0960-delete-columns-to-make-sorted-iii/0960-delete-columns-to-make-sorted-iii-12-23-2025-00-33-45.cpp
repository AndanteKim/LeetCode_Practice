class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int N = strs.size(), W = strs[0].size();
        vector<int> dp(W, 1);

        for (int i = W - 2; i >= 0; --i){
            for (int j = i + 1; j < W; ++j) {
                bool isSorted = true;

                for (const string& row : strs) {
                    if (row[i] > row[j]) {
                        isSorted = false;
                        break;
                    }
                }

                if (isSorted) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        
        return W - *max_element(dp.begin(), dp.end());
    }
};