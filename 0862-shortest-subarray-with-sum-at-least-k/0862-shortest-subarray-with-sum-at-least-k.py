class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        n = len(nums)
        
        # Size is n + 1 to handle subarrays starting from index 0
        prefix_sums = [0] * (n + 1)
        
        # Calculate prefix sums
        for i in range(1, n + 1):
            prefix_sums[i] = prefix_sums[i - 1] + nums[i - 1]
            
        candidate_idx, ans = deque(), float('inf')
        
        for i in range(n + 1):
            # Remove candidates from front of deque where subarray sum meets target
            while candidate_idx and prefix_sums[i] - prefix_sums[candidate_idx[0]] >= k:
                # Update shortest subarray length
                ans = min(ans, i - candidate_idx.popleft())
            
            # Maintain monotonicity by removing indices with larger prefix sums
            while candidate_idx and prefix_sums[i] <= prefix_sums[candidate_idx[-1]]:
                candidate_idx.pop()
            
            # Add current index to candidates
            candidate_idx.append(i)
        
        # Return -1 if no valid subarray found
        return -1 if ans == float('inf') else ans