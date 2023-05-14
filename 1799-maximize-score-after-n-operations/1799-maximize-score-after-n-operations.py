class Solution:
    def backtrack(self, nums: List[int], mask: int, pairsPicked: int, memo: List[int]) -> int:
        if 2 * pairsPicked == len(nums):
            return 0
        
        if memo[mask] != -1:
            return memo[mask]
        
        maxScore = 0
        
        for firstIndex in range(len(nums)):
            for secondIndex in range(firstIndex + 1, len(nums)):
                if (mask >> firstIndex) & 1 == 1 or (mask >> secondIndex) & 1 == 1:
                    continue
                newMask = mask | (1 << firstIndex) | (1 << secondIndex)
                
                currScore = (pairsPicked + 1) * math.gcd(nums[firstIndex], nums[secondIndex])
                remainingScore = self.backtrack(nums, newMask, pairsPicked + 1, memo)
                
                maxScore = max(maxScore, currScore + remainingScore)
        
        memo[mask] = maxScore
        return maxScore
    
    def maxScore(self, nums: List[int]) -> int:
        memoSize = 1 << len(nums)
        memo = [-1] * memoSize
        
        return self.backtrack(nums, 0, 0, memo)