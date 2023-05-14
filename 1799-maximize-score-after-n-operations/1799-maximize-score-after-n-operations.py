class Solution:
    def maxScore(self, nums: List[int]) -> int:
        maxStates = 1 << len(nums)
        finalMask = maxStates - 1
        
        dp = [0] * maxStates
        
        for state in range(finalMask, -1, -1):
            if state == finalMask:
                dp[state] == 0
                continue
            
            numbersTaken = bin(state).count('1')
            pairsFormed = numbersTaken // 2
            
            if numbersTaken % 2:
                continue
            
            for firstIndex in range(len(nums)):
                for secondIndex in range(firstIndex + 1, len(nums)):
                    if (state >> firstIndex & 1) == 1 or (state >> secondIndex & 1) == 1:
                        continue
                    currentScore = (pairsFormed + 1) * math.gcd(nums[firstIndex], nums[secondIndex])
                    stateAfterPickingCurrPair = state | (1 << firstIndex) | (1 << secondIndex)
                    remainingScore = dp[stateAfterPickingCurrPair]
                    dp[state] = max(dp[state], currentScore + remainingScore)
                    
        return dp[0]
                    
                    
                    