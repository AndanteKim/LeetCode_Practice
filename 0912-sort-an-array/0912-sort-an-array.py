class Solution:
    def mergesort(self, nums: List[int]) -> List[int]:
        if len(nums) > 1:
            mid = len(nums) // 2
            Left = nums[:mid]
            Right = nums[mid:]
            
            self.mergesort(Left)
            self.mergesort(Right)
            
            i = j = k = 0
            
            while i < len(Left) and j < len(Right):
                if Left[i] <= Right[j]:
                    nums[k] = Left[i]
                    i += 1
                else:
                    nums[k] = Right[j]
                    j += 1
                k += 1
            
            while i < len(Left):
                nums[k] = Left[i]
                i += 1
                k += 1
            
            while j < len(Right):
                nums[k] = Right[j]
                j += 1
                k += 1
            return nums
    
    def sortArray(self, nums: List[int]) -> List[int]:
        if len(nums) <= 1:
            return nums
        return self.mergesort(nums)