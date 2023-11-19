class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        lowest, start, counting = float('inf'), float('-inf'), [0] * (5 * (10 ** 4) + 1)
        
        for num in nums:
            counting[num] += 1
            lowest = min(lowest, num)
            start = max(start, num)
        
        ans, curr, prev = 0, start - 1, start
        while counting[lowest] < len(nums):
            if counting[curr] != 0:
                ans += counting[prev]
                counting[curr] += counting[prev]
                prev = curr
                
            curr -= 1
        
        return ans
        