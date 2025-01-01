class Solution:
    def maxScore(self, s: str) -> int:
        # One pass
        ones, zeros, best = 0, 0, float('-inf')

        for i in range(0, len(s) - 1):
            if s[i] == '1':
                ones += 1
            else:
                zeros += 1

            best = max(best, zeros - ones)

        if s[-1] == '1':
            ones += 1

        return best + ones