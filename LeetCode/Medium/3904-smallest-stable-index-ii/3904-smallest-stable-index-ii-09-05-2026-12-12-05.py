class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        ans, n = 0, len(nums)
        curr_mx = mx_at_ans = float('-inf')

        for i, num in enumerate(nums):
            curr_mx = max(curr_mx, num)
            if i == ans:
                mx_at_ans = max(mx_at_ans, num)
            
            if num < mx_at_ans - k:
                ans = i + 1
                mx_at_ans = curr_mx

        return ans if ans < n else -1