class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        # Base case: If there's only one element, the maximum beauty is 1
        if len(nums) == 1:
            return 1
        
        max_val = max(nums)     # Find the maximum value in nums
        count = [0] * (max_val + 1)     # Array to track count changes
        
        # Update the count array for the range [val - k, val + k]
        for num in nums:
            count[max(num - k, 0)] += 1     # Increment at the start of the range
            count[min(num + k + 1, max_val)] -= 1   # Decrement after the range
            
        max_beauty, curr_sum = 0, 0     # Tracks the running sum of counts
        
        # Calculate the prefix sum and find the maximum beauty
        for val in count:
            curr_sum += val
            max_beauty = max(max_beauty, curr_sum)
            
        return max_beauty