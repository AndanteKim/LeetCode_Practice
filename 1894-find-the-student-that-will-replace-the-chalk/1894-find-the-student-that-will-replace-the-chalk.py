class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        if not chalk:
            return 0
        
        remain, i, n = k, 0, len(chalk)
        prefix_sum = [0] * (n + 1)

        for i in range(1, n + 1):
            prefix_sum[i] = prefix_sum[i - 1] + chalk[i - 1]
        
        remain %= prefix_sum[-1]
        
        for i in range(n + 1):
            if 0 <= remain < prefix_sum[i]:
                return i - 1
        
        return -1