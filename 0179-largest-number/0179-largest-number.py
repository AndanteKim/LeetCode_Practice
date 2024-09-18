class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        # Sort the numbers using Quick sort
        self._quick_sort(nums, 0, len(nums) - 1)
        # Concatenate sorted numbers to form the largest number
        largest = "".join(map(str, nums))
        # Handle the case wehre the largest number is zero
        return "0" if largest[0] == "0" else largest
    
    def _quick_sort(self, nums: List[int], left: int, right: int) -> None:
        # Base case: If the range has one or no elements, it's already sorted
        if left >= right:
            return
        
        # Partition the array and get the pivot index
        pivot = self._partition(nums, left, right)
        
        # Recursively the array and get the pivot index
        self._quick_sort(nums, left, pivot - 1)
        self._quick_sort(nums, pivot + 1, right)
        
    def _partition(self, nums: List[int], left: int, right: int) -> int:
        pivot = nums[right]
        low_idx = left
        
        # Rearrange elements so that those greater than the pivot are on the left
        for i in range(left, right):
            if self._compare(nums[i], pivot):
                nums[i], nums[low_idx] = nums[low_idx], nums[i]
                low_idx += 1
                
        # Place the pivot in its correct position
        nums[low_idx], nums[right] = nums[right], nums[low_idx]
        return low_idx
    
    def _compare(self, first_num: int, second_num: int) -> bool:
        # Compare concatenated strings to decide the order
        return str(first_num) + str(second_num) > str(second_num) + str(first_num)
        
        