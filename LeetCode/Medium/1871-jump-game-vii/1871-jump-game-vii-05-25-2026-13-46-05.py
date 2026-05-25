class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        n = len(s)
        dp, prefix = [0] * n, [0] * n
        dp[0] = 1

        for i in range(minJump):
            prefix[i] = 1

        for i in range(minJump, n):
            left, right = i - maxJump, i - minJump

            if s[i] == '0':
                total = prefix[right] - (0 if left <= 0 else prefix[left - 1])
                dp[i] = int(total != 0)
            prefix[i] = prefix[i - 1] + dp[i]

        return bool(dp[n - 1])