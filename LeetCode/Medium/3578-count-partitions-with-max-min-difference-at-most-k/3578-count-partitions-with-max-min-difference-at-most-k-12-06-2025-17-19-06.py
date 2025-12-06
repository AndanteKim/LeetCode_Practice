class Solution:
    def countPartitions(self, nums: List[int], k: int) -> int:
        n, mod = len(nums), 10 ** 9 + 7
        dp, prefix = [0] * (n + 1), [0] * (n + 1)
        cnt = SortedList()
        dp[0], prefix[0] = 1, 1

        j = 0
        for i in range(n):
            cnt.add(nums[i])

            # adjust window
            while j <= i and cnt[-1] - cnt[0] > k:
                cnt.remove(nums[j])
                j += 1
            
            dp[i + 1] = (prefix[i] - (prefix[j - 1] if j > 0 else 0)) % mod
            prefix[i + 1] = (prefix[i] + dp[i + 1]) % mod
        
        return dp[n]