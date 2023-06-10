class Solution:
    def find_rotate_index(self, left: int, right: int, nums: List[int]) -> int:
        if nums[left] < nums[right]:
            return 0
        
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] > nums[mid + 1]:
                return mid + 1
            else:
                if nums[mid] < nums[left]:
                    right = mid - 1
                else:
                    left = mid + 1
                    
        return -1
                    
    def partial_search(self, left: int, right: int, nums: List[int], target: int) -> int:
        while left <= right:
            mid = (left + right) // 2
            
            if nums[mid] == target:
                return mid
            
            else:
                if target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
        return -1
    
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        
        if n == 1:
            return 0 if nums[0] == target else -1
        
        rotate_index = self.find_rotate_index(0, n - 1, nums)
        
        if nums[rotate_index] == target:
            return rotate_index
        
        if rotate_index == 0:
            return self.partial_search(0, n - 1, nums, target)
        if target < nums[0]:
            return self.partial_search(rotate_index, n - 1, nums, target)
        return self.partial_search(0, rotate_index, nums, target)