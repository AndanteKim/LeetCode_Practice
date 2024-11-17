class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        # Initialize result to the maximum possible integer value
        n, ans = len(nums), float('inf')
        
        # Min-heap to store cumulative sum and its corresponding index
        cumulative_sum, prefix_sum_heap = 0, []
        
        # Iterate through the array
        for i in range(n):
            # Update cumulative sum
            cumulative_sum += nums[i]
            
            # If cumulative sum is already >= k, update the shortest length
            if cumulative_sum >= k:
                ans = min(ans, i + 1)
            
            # Remove subarrays from heap that can form a valid subarray
            while prefix_sum_heap and cumulative_sum - prefix_sum_heap[0][0] >= k:
                # Update shortest subarray length
                _, prev_idx = heappop(prefix_sum_heap)
                ans = min(ans, i - prev_idx)
            
            # Add current cumulative sum and index to heap
            heappush(prefix_sum_heap, (cumulative_sum, i))
        
        # Return -1 if no valid subarray found
        return -1 if ans == float('inf') else ans
        