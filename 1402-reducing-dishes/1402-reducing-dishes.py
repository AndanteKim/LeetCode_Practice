class Solution:
    def findMaxSatisfaction(self, satisfaction: List[int], memo: List[List[int]], index: int, time: int) -> int:
        if index == len(satisfaction):
            return 0
        
        if memo[index][time] != -1:
            return memo[index][time]
        
        memo[index][time] = max(satisfaction[index] * time + \
                                self.findMaxSatisfaction(satisfaction, memo, index + 1, time + 1),\
                                self.findMaxSatisfaction(satisfaction, memo, index + 1, time))
        return memo[index][time]
    
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        satisfaction.sort()
        m = len(satisfaction)
        memo = [[-1] * (m + 1) for _ in range(m+1)]
        
        return self.findMaxSatisfaction(satisfaction, memo, 0, 1)