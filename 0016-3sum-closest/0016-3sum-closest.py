class Solution:
    def two_sum(self, nums: List[int], start_index: int, target: int) -> int:
        left, right = start_index, self.n - 1
        curr = nums[left] + nums[right]
        
        while left < right:
            if nums[left] + nums[right] == target:
                return target
            elif nums[left] + nums[right] < target:
                if abs(curr - target) > abs(nums[left] + nums[right] - target):
                    curr = nums[left] + nums[right]
                left += 1
            else:
                if abs(curr - target) > abs(nums[left] + nums[right] - target):
                    curr = nums[left] + nums[right]
                right -= 1
            
        return curr
    
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        ans, self.n = float('inf'), len(nums)
        nums.sort()
        
        for i in range(self.n - 2):
            curr = nums[i] + self.two_sum(nums, i + 1, target - nums[i])
            if (abs(ans - target) > abs(curr - target)):
                ans = curr
        
        return ans