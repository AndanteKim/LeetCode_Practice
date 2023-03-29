class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        satisfaction.sort()
        if satisfaction[-1] < 0:
            return 0
        ans = 0
        
        for i in range(len(satisfaction)-1):
            curr, time = 0, 1
            for j in range(i, len(satisfaction)):
                curr += time * satisfaction[j]
                time += 1
            ans = max(ans, curr)
        
        return ans
        