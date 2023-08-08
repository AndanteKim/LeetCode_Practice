class Solution:
    def binary_search(self, left: int, right: int, target: int, nums: List[int]) -> int:
        while left <= right:
            mid = left + ((right - left) >> 1)
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        
        return -1
    
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        left, right = 0, n - 1
        
        while left <= right:
            mid = left + ((right - left) >> 1)
            if nums[mid] > nums[-1]:
                left = mid + 1
            else:
                right = mid - 1
        
        ans = self.binary_search(0, left - 1, target, nums)
        return ans if ans != -1 else self.binary_search(left, n - 1, target, nums)
        