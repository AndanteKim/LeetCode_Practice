class Solution:
    def minBuildTime(self, blocks: List[int], split: int) -> int:
        # sort the blocks in descending order
        N = len(blocks)
        blocks.sort(reverse = True)
        
        # Initialize the dp array
        dp = [[0] * (N + 1) for _ in range(N + 1)]
        
        # base case 1: If there are no workers, then we can't build any block
        for b in range(N):
            dp[b][0] = float('inf')
            
        # base case 2: If there are no blocks, then we don't need any time.
        for w in range(N + 1):
            dp[N][w] = 0
            
        # fill the dp array in a bottom-up fashion
        for b in range(N - 1, -1, -1):
            # base case 3: If we have more workers than blocks,
            # then we can build all the blocks
            for w in range(N, 0, -1):
                if w >= N - b:
                    dp[b][w] = blocks[b]
                    continue
                
                # Recurrence relation
                workHere = max(blocks[b], dp[b + 1][w - 1])
                splitHere = split + dp[b][min(2 * w, N - b)]
                
                # Store the result in the dp array
                dp[b][w] = min(workHere, splitHere)
        
        # For building all the blocks with initially 1 worker
        return dp[0][1]
                
        