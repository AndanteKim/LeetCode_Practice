class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        satisfaction.sort()
        maxSatisfaction, suffixSum = 0, 0
        
        for i in range(len(satisfaction) - 1, -1, -1):
            if suffixSum + satisfaction[i] > 0:
                suffixSum += satisfaction[i]
                maxSatisfaction += suffixSum
        
        return maxSatisfaction