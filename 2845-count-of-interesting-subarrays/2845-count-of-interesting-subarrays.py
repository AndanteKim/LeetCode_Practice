class Solution:
    def countInterestingSubarrays(self, nums: List[int], modulo: int, k: int) -> int:
        n, cnt = len(nums), Counter([0])
        ans, prefix = 0, 0

        for i in range(n):
            prefix += 1 if nums[i] % modulo == k else 0
            ans += cnt[(prefix - k + modulo) % modulo]
            cnt[prefix % modulo] += 1

        return ans