class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        ans, prev, total = 0, 0, 0
        
        for num in nums:
            if prev < num:
                total += num
            else:
                total = num
            prev = num
            ans = max(ans, total)
        
        return ans