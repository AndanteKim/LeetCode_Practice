class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        deleted, left, n, ans = 0, 0, len(nums), 0
        curr_1 = 0

        for right in range(n):
            while left < right and deleted > 1:
                if nums[left] == 0:
                    deleted -= 1
                else:
                    curr_1 -= 1
                left += 1
            
            if nums[right] == 0:
                deleted += 1
            else:
                curr_1 += 1
            ans = max(ans, curr_1)

        if ans > 0 and deleted == 0:
            ans -= 1
        
        return ans