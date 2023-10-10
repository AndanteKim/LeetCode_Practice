class Solution:
    def minOperations(self, nums: List[int]) -> int:
        # Binary search
        # Time complexity: O(nlogn), Space Complexity: O(n)
        
        new_nums, n = sorted(set(nums)), len(nums)
        ans = n
        
        for i in range(len(new_nums)):
            left = new_nums[i]
            right = left + n - 1
            j = bisect_right(new_nums, right)
            count = j - i
            ans = min(ans, n - count)
            
        return ans