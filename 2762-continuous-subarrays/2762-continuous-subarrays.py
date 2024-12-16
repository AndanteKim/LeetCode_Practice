class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        n, left, right, ans = len(nums), 0, 0, 0
        # Two heaps to track min/max indices, sorted by nums[index]
        # (nums[i], i) tuples for min tracking
        # (-nums[i], i) tuples for max tracking 
        min_heap, max_heap = [], []
        
        for right in range(n):
            # Add current index to both heaps
            # For max heap, negate value to convert min heap to max heap
            heappush(min_heap, (nums[right], right))
            heappush(max_heap, (-nums[right], right))
            
            # While window violates |nums[i] - nums[j]| <= 2
            # Shrink window from left and remove outdates indices
            while left < right and -max_heap[0][0] - min_heap[0][0] > 2:
                left += 1
                
                # Remove indices outside window from both heaps
                while min_heap and min_heap[0][1] < left:
                    heappop(min_heap)
                    
                while max_heap and max_heap[0][1] < left:
                    heappop(max_heap)
            
            ans += right - left + 1
            
        return ans