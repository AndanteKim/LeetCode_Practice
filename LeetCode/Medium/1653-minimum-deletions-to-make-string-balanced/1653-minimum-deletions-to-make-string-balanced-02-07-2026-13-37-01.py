class Solution:
    def minimumDeletions(self, s: str) -> int:
        if len(s) == 1:
            return 0

        n = len(s)
        a_cnt, b_cnt, ans = [0] * n, [0] * n, n
        a_cnt[-1] = 1 if s[-1] == 'a' else 0
        b_cnt[0] = 1 if s[0] == 'b' else 0

        for i in range(1, n):
            if s[i] == 'b':
                b_cnt[i] = b_cnt[i - 1] + 1
            else:
                b_cnt[i] = b_cnt[i - 1]

        for i in range(n - 2, -1, -1):
            if s[i] == 'a':
                a_cnt[i] = a_cnt[i + 1] + 1
            else:
                a_cnt[i] = a_cnt[i + 1]
        
        ans = min(a_cnt[0], b_cnt[n - 1])
        for i in range(n - 1):
            ans = min(ans, a_cnt[i + 1] + b_cnt[i])

        return ans