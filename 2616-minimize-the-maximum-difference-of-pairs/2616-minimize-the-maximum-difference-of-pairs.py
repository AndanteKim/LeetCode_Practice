class Solution:
    def countValidPairs(self, threshold: int, nums: List[int]) -> int:
        index, count = 0, 0
        while index < self.n - 1:
            if nums[index + 1] - nums[index] <= threshold:
                count += 1
                index += 1
            index += 1
        return count
            
    
    def minimizeMax(self, nums: List[int], p: int) -> int:
        nums.sort()
        self.n = len(nums)
        
        left, right = 0, nums[-1] - nums[0]
        while left < right:
            mid = left + ((right - left) >> 1)
            
            if self.countValidPairs(mid, nums) >= p:
                right = mid
            else:
                left = mid + 1
        return left