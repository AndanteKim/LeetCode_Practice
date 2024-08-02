class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        op1 = self.min_swaps(nums, 0)   # Grouping all 0s together
        op2 = self.min_swaps(nums, 1)   # Grouping all 1s together
        return min(op1, op2)
    
    def min_swaps(self, data: List[int], val: int) -> int:
        n = len(data)
        right_suffix_sum = [0] * (n + 1)
        
        # Construct the suffix sum array for counting opposite values
        # (val ^ 1)
        for i in range(n - 1, -1, -1):
            right_suffix_sum[i] = right_suffix_sum[i + 1]
            if data[i] == (val ^ 1):
                right_suffix_sum[i] += 1
                
        # Total zeros in the array if 'val' is 1 (or vice versa)
        total_swaps = right_suffix_sum[0]
        
        # Track current number of required swaps in the current segment
        curr_swap = 0
        min_swaps = total_swaps - right_suffix_sum[n - total_swaps]
        
        # Iterate to find the minimum swaps by sliding
        # the potential block of grouped 'val'
        for i in range(total_swaps):
            if data[i] == val ^ 1:
                curr_swap += 1
                
            remaining = total_swaps - i - 1
            required_swaps = ((i + 1) - curr_swap) + (remaining - right_suffix_sum[n - remaining])
            
            min_swaps = min(min_swaps, required_swaps)
            
        return min_swaps
                
    