class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        def find_upper_bound(target: int) -> int:
            lo, hi, res = 0, n - 1, 0
            
            # Perform binary search to find the upper bound
            while lo <= hi:
                mid = lo + ((hi - lo) >> 1)
                if nums[mid] <= target:
                    res = mid   # Update the result and move to the right half
                    lo = mid + 1
                else:
                    hi = mid - 1    # Move to the left half
            
            return res
        
        max_beauty, n = 0, len(nums)
        nums.sort()
        
        for i in range(n):
            # Find the farthest index where the value is within the range [num, num + 2 * k]
            upper_bound = find_upper_bound(nums[i] + 2 * k)
            
            # Update the maximum beauty based on the current range
            max_beauty = max(max_beauty, upper_bound - i + 1)
            
        return max_beauty