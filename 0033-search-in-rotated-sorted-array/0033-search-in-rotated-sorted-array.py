class Solution:
    def shifted_binary_search(self, pivot: int, target: int, nums: List[int]) -> int:
        shift = self.n - pivot
        left, right = (pivot + shift) % self.n, (pivot - 1 + shift) % self.n
        
        while left <= right:
            mid = left + ((right - left) >> 1)
            if nums[(mid - shift) % self.n] == target:
                return (mid - shift) % self.n
            elif nums[(mid - shift) % self.n] > target:
                right = mid - 1
            else:
                left = mid + 1
        
        return -1
    
    def search(self, nums: List[int], target: int) -> int:
        self.n = len(nums)
        left, right = 0, self.n - 1
        
        while left <= right:
            mid = left + ((right - left) >> 1)
            if nums[mid] > nums[-1]:
                left = mid + 1
            else:
                right = mid - 1
        
        return self.shifted_binary_search(left, target, nums)