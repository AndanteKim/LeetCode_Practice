class Solution:
    
    def counting_sort(self) -> None:
        counts = dict()
        minVal, maxVal = min(self.nums), max(self.nums)
        for val in self.nums:
            counts[val] = counts.get(val, 0) + 1
        
        index = 0
        for val in range(minVal, maxVal + 1):
            while counts.get(val, 0) > 0:
                self.nums[index] = val
                index += 1
                counts[val] -= 1
            
    
    def sortArray(self, nums: List[int]) -> List[int]:
        self.nums = nums
        self.counting_sort()
        return self.nums