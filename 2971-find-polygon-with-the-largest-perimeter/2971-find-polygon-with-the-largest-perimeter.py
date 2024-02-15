class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()
        prev_sum, ans = 0, -1
        
        for num in nums:
            if num < prev_sum:
                ans = num + prev_sum
            prev_sum += num
        
        return ans
        