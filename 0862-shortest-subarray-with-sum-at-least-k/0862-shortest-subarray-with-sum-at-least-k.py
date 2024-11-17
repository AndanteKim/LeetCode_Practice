class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        # Binary search to find the largest index where cumulative sum is <= target
        def _find_candidate_idx(target: int) -> int:
            left, right = 0, len(stack) - 1
            
            while left <= right:
                mid = left + ((right - left) >> 1)
                
                if stack[mid][0] <= target:
                    left = mid + 1
                else:
                    right = mid - 1
                
            return right
        
        # Stack-like list to store cumulative sums and their indices
        n, stack = len(nums), [(0, -1)]
        cumulative_sum, ans = 0, float('inf')
        
        for i in range(n):
            # Update cumulative sum
            cumulative_sum += nums[i]
            
            # Remove entries from stack that are larger than current cumulative sum
            while stack and cumulative_sum <= stack[-1][0]:
                stack.pop()
            
            # Add current sum and index to stack
            stack.append((cumulative_sum, i))
            
            candidate_idx = _find_candidate_idx(cumulative_sum - k)
            
            # If a valid candidate is found, update the shortest subarray length
            if candidate_idx != -1:
                ans = min(ans, i - stack[candidate_idx][1])
        
        # Return -1 if no valid subarray found
        return ans if ans != float('inf') else -1