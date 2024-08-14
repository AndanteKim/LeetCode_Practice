class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        nums.sort()
        self.n = len(nums)
        
        # Initialize binary search range
        low, high = 0, nums[-1] - nums[0]
        while low < high:
            mid = (low + high) >> 1
            
            # Count pairs with distance <= mid
            count = self._count_pairs_with_max_distance(nums, mid)
            
            # Adjust binary search bounds based on count
            if count < k:
                low = mid + 1
            else:
                high = mid
                
        return low
    
    # Count number of pairs with distance <= max_dist using a moving window
    def _count_pairs_with_max_distance(self, nums: List[int], max_dist: int) -> int:
        count, left = 0, 0
        
        for right in range(0, self.n):
            # Adjust the left pointer to maintain the window with distances <= max_dist
            while nums[right] - nums[left] > max_dist:
                left += 1
            
            # Add the number of valid pairs ending at the current right index
            count += right - left
            
        return count
            
        
        