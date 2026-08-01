class Solution:
    def minBuildTime(self, blocks: List[int], split: int) -> int:
        def dp(b: int, w: int) -> int:
            # Base case
            if b == n:
                return 0
            
            if w == 0:
                return float('inf')

            if w >= n - b:
                return blocks[b]

            if memo[b][w] != -1:
                return memo[b][w]

            work_here = max(blocks[b], dp(b + 1, w - 1))
            split_here = split + dp(b, min(2 * w, n - b))

            memo[b][w] = min(work_here, split_here)
            return memo[b][w]
        
        n = len(blocks)
        blocks.sort(reverse = True)
        memo = [[-1] * (n + 1) for _ in range(n)]

        return dp(0, 1)