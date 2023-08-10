class Solution:
    def isBinarySearchHelpful(self, nums: List[int], start: int, element: int) -> bool:
        return nums[start] != element
    
    def existsInFirst(self, nums: List[int], start: int, element: int) -> bool:
        return nums[start] <= element
    
    def search(self, nums: List[int], target: int) -> bool:
        n = len(nums)
        left, right = 0, n - 1
        
        while left <= right:
            mid = left + ((right - left) >> 1)
            if nums[mid] == target:
                return True
            
            if not self.isBinarySearchHelpful(nums, left, nums[mid]):
                left += 1
                continue
            
            pivotArray = self.existsInFirst(nums, left, nums[mid])
            targetArray = self.existsInFirst(nums, left, target)
            if pivotArray ^ targetArray:
                if pivotArray:
                    left = mid + 1
                else:
                    right = mid - 1
            else:
                if nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1
        return False