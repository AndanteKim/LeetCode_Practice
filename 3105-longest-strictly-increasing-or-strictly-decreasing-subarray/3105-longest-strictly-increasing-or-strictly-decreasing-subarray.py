class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        n, ans = len(nums), 0

        for i in range(n):
            inc_cnt, prev = 1, nums[i]
            for j in range(i + 1, n):
                if prev < nums[j]:
                    inc_cnt += 1
                    prev = nums[j]
                else:
                    break
                ans = max(ans, inc_cnt)

        for i in range(n):
            dec_cnt, prev = 1, nums[i]
            for j in range(i + 1, n):
                if prev > nums[j]:
                    dec_cnt += 1
                    prev = nums[j]
                else:
                    break
                ans = max(ans, dec_cnt)

        return max(ans, 1)