class Solution:
    def threeSumSmaller(self, nums: List[int], target: int) -> int:
        nums.sort()
        ans, self.n = 0, len(nums)
        
        for i in range(self.n - 2):
            ans += self.two_sum_smaller(nums, i + 1, target - nums[i])
        
        return ans
    
    def two_sum_smaller(self, nums: List[int], start_index: int, target: int) -> int:
        total, left, right = 0, start_index, self.n - 1
        
        while left < right:
            if nums[left] + nums[right] < target:
                total += right - left
                left += 1
            else:
                right -= 1
        
        return total