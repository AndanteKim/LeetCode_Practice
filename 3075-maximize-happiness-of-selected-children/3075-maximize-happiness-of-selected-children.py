class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        happiness.sort(reverse = True)
        
        ans, curr = 0, 0
        for i in range(k):
            if curr > happiness[i]:
                break
            ans += happiness[i] - curr
            curr += 1
            
        return ans
        