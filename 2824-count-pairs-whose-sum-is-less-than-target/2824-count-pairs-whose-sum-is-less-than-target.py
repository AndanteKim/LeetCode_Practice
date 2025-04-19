class Solution:
    def countPairs(self, nums: List[int], target: int) -> int:
        def binary_search(num: int, left: int, right: int) -> int:
            while left <= right:
                mid = left + ((right - left) >> 1)
                if nums[mid] < target - num:
                    left = mid + 1
                else:
                    right = mid - 1
            
            return right
        
        nums.sort()
        ans, n = 0, len(nums)

        for left in range(n - 1):
            right = binary_search(nums[left], left + 1, n - 1)
            
            ans += right - left

        return ans