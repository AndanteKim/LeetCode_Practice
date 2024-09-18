class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        # Sort the numbers using merge sort
        sorted_nums = self._merge_sort(nums, 0, len(nums) - 1)
        
        # Concatenate sorted numbers to form the largest number
        largest = "".join(map(str, sorted_nums))
        
        # Handle the case where the largest number is zero
        return "0" if largest[0] == "0" else largest
    
    def _merge_sort(self, nums: List[int], left: int, right: int) -> List[int]:
        # Base case: A single element is already sorted
        if left >= right:
            return [nums[left]]
        mid = (left + right) >> 1
        
        # Recursively sort the left and right halves
        left_half = self._merge_sort(nums, left, mid)
        right_half = self._merge_sort(nums, mid + 1, right)
        
        # Merge the sorted halves
        return self._merge(left_half, right_half)
    
    def _merge(self, left_half: List[int], right_half: List[int]) -> List[int]:
        sorted_nums = []
        left_idx, right_idx = 0, 0
        
        # Merge the two halves based on custom comparison
        while left_idx < len(left_half) and right_idx < len(right_half):
            if self._compare(left_half[left_idx], right_half[right_idx]):
                sorted_nums.append(left_half[left_idx])
                left_idx += 1
            else:
                sorted_nums.append(right_half[right_idx])
                right_idx += 1
                
        # Append remaining elements from the left half
        sorted_nums.extend(left_half[left_idx:])
        
        # Append remaining elements from the right half
        sorted_nums.extend(right_half[right_idx:])
        return sorted_nums
    
    def _compare(self, first_num: int, second_num: int) -> bool:
        # Compare concatenated strings to decide the order
        return str(first_num) + str(second_num) > str(second_num) + str(first_num)
        