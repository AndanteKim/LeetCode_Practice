class Solution {
    int gcd(int x, int y){
        while(y){
            int temp = x;
            x = y;
            y = temp % y;
        }
        return x;
    }
    
    int backtrack(vector<int>& nums, int mask, int pairsPicked, vector<int>& memo){
        if (2 * pairsPicked == nums.size()) return 0;
        if (memo[mask] != -1) return memo[mask];
        int maxScore = 0;
        
        for (int firstIndex = 0; firstIndex < nums.size(); ++firstIndex){
            for(int secondIndex = firstIndex + 1; secondIndex < nums.size(); ++secondIndex){
                if (((mask >> firstIndex) & 1) == 1 or ((mask >> secondIndex) & 1) == 1) continue;
                int newMask = mask | (1 << firstIndex) | ((1 << secondIndex));
                int currScore = (pairsPicked + 1) * gcd(nums[firstIndex], nums[secondIndex]);
                int remainingScore = backtrack(nums, newMask, pairsPicked + 1, memo);
                maxScore = max(maxScore, currScore + remainingScore);
            }
        }
        memo[mask] = maxScore;
        return maxScore;
    }
    
public:
    int maxScore(vector<int>& nums) {
        int memoSize = 1 << nums.size();
        vector<int> memo(memoSize, -1);
        
        return backtrack(nums, 0, 0, memo);
    }
};