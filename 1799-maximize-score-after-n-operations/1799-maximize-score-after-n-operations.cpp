class Solution {
public:
    int maxScore(vector<int>& nums) {
        int maxStates = 1 << nums.size();
        int finalMask = maxStates - 1;
        
        vector<int> dp(maxStates);
        
        for (int state = finalMask; state >= 0; --state){
            if(state == finalMask){
                dp[state] == 0;
                continue;
            }
            
            int numbersTaken = __builtin_popcount(state);
            int pairsFormed = numbersTaken / 2;
            
            if (numbersTaken % 2) continue;
            
            for (int firstIndex = 0; firstIndex < nums.size(); ++firstIndex){
                for (int secondIndex = firstIndex + 1; secondIndex < nums.size(); ++secondIndex){
                    if (((state >> firstIndex) & 1) == 1 || ((state >> secondIndex) & 1) == 1)
                        continue;
                    int currentScore = (pairsFormed + 1) * __gcd(nums[firstIndex], nums[secondIndex]);
                    int stateAfterPickingCurrPair = state | (1 << firstIndex) | (1 << secondIndex);
                    int remainingScore = dp[stateAfterPickingCurrPair];
                    dp[state] = max(dp[state], currentScore + remainingScore);
                }
            }
        }
        
        return dp[0];
    }
};