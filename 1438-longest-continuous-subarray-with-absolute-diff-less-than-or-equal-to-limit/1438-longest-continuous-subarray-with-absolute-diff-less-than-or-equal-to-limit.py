class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        max_heap, min_heap = [], []
        
        left, max_length = 0, 0
        
        for right in range(len(nums)):
            heappush(max_heap, (-nums[right], right))
            heappush(min_heap, (nums[right], right))
            
            # Check if the absolutue difference between the maximum and minimum values in the current window
            # exceeds the limit
            while -max_heap[0][0] - min_heap[0][0] > limit:
                # Move the left pointer to the right until the condition is satisfied.
                # This ensures we remove the element causing the violation
                left = min(max_heap[0][1], min_heap[0][1]) + 1
                
                # Remove elements from the heaps that are outside the current window
                while max_heap[0][1] < left:
                    heappop(max_heap)
                while min_heap[0][1] < left:
                    heappop(min_heap)
                    
            # Update max_length with the length of the current valid window
            max_length = max(max_length, right - left + 1)
        
        return max_length