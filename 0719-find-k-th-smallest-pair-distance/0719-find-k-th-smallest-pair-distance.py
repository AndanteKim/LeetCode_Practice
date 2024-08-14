class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        
        # Highest element in the sorted array
        max_elem = nums[-1]
        
        # Maximum possible distance
        max_possible_dist = max_elem * 2
        
        # Initialize arrays for prefix counts and value counts
        prefix_cnt = [0] * max_possible_dist
        value_cnt = [0] * (max_elem + 1)
        
        # Populate prefix count and value count
        idx = 0
        
        for val in range(max_possible_dist):
            while idx < n and nums[idx] <= val:
                idx += 1
                
            prefix_cnt[val] = idx
            
        for i in range(n):
            value_cnt[nums[i]] += 1
            
        # Binary search to find kth smallest distance
        left, right = 0, max_elem
        while left < right:
            mid = (left + right) >> 1
            
            # Count pairs with distance <= mid
            cnt = self._count_pairs(nums, prefix_cnt, value_cnt, mid)
            
            # Adjust binary search bounds based on count
            if cnt < k:
                left = mid + 1
            else:
                right = mid
                
        return left
    
    def _count_pairs(self, nums: List[int], prefix_cnt: List[int], value_cnt: List[int], max_dist: int) -> int:
        cnt, n, idx = 0, len(nums), 0
        
        while idx < n:
            curr_val = nums[idx]
            value_cnt_for_curr = value_cnt[curr_val]
            
            # Calculate pairs involving current value with distance <= max_distance
            pairs_with_larger_values = prefix_cnt[min(curr_val + max_dist, len(prefix_cnt) - 1)] - prefix_cnt[curr_val]
            
            pairs_with_same_values = (value_cnt_for_curr * (value_cnt_for_curr - 1)) >> 1
            
            cnt += pairs_with_larger_values * value_cnt_for_curr + pairs_with_same_values
            
            # Skip duplicate values
            while idx + 1 < n and nums[idx] == nums[idx + 1]:
                idx += 1
            idx += 1
            
        return cnt