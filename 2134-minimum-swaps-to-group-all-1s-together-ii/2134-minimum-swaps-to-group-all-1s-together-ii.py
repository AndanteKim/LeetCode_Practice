class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        # Calculate the minimum swaps needed to group all 1s or all 0s together
        op1 = self.min_swaps_helper(nums, 0)    # Grouping all 0s together
        op2 = self.min_swaps_helper(nums, 1)    # Grouping all 1s together
        
        return min(op1, op2)
        
    def min_swaps_helper(self, data: List[int], val: int) -> int:
        n, total = len(data), 0
        
        # Count the total number of 'val' in the array
        for i in range(n - 1, -1, -1):
            if data[i] == val:
                total += 1
                
        # If there is no 'val' or the array is full of 'val', no swaps are needed
        if total == 0 or total == n:
            return 0
        
        start, end = 0, 0
        max_val, curr_val = 0, 0
        
        # Initial window setup: count the number of 'val' in the first window of size 'curr_val'
        while end < total:
            if data[end] == val:
                curr_val += 1
            end += 1
            
        max_val = max(max_val, curr_val)
        
        # Slide the window across the array to find the maximum number of 'val' in any window
        while end < n:
            if data[start] == val:
                curr_val -= 1
            
            start += 1
            if data[end] == val:
                curr_val += 1
            end += 1
            max_val = max(max_val, curr_val)
            
        # Minimum swaps are the total 'val' - the maximum found in any window
        return total - max_val