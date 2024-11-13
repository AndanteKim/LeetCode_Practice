class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        # Calculate the number of pairs with sum less than 'value'.
        def lower_bound(val: int) -> int:
            left, right, ans = 0, len(nums) - 1, 0
            
            while left <= right:
                two_sum = nums[left] + nums[right]
                
                # If two sum is less than value, add the size of window to result and move to the next index.
                if two_sum < val:
                    ans += right - left
                    left += 1
                else:
                    # Otherwise, shift the right pointer backwards, until we get a valid window.
                    right -= 1
                    
            return ans
        
        nums.sort()
        return lower_bound(upper + 1) - lower_bound(lower)
    
    
        