class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        min_val, total = 0, 0
        
        for num in nums:
            total += num
            min_val = min(min_val, total)
        
        return -min_val + 1