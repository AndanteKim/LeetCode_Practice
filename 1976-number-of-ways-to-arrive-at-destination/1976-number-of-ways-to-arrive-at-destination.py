class Solution:
    MOD = 10 ** 9 + 7
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        # dp[src][dst][0] stores the minimum time between src and dest
        # dp[src][dst][1] stores the number of ways to reach dest from src
        # with the minimum time
        dp = [[[0, 0] for _ in range(n)] for _ in range(n)]

        # Initialize the dp table
        for src in range(n):
            for dst in range(n):
                if src != dst:
                    # Set a large initial time
                    dp[src][dst][0] = int(1e12)
                    # No paths yet
                    dp[src][dst][1] = 0
                else:
                    # Distance from a node to itself is 0
                    dp[src][dst][0] = 0
                    # Only one trivial way (staying at the node)
                    dp[src][dst][1] = 1

        # Initialize direct roads from the input
        for start, end, t in roads:
            dp[start][end][0] = t
            dp[end][start][0] = t

            # There is one direct path
            dp[start][end][1] = 1

            # Since the roads are bidirectional
            dp[end][start][1] = 1
        
        # Apply the Floyd-Warshall algorithm to compute the shortest paths
        # Intermediate node
        for mid in range(n):
            # Starting node
            for src in range(n):
                # Destination node
                for dst in range(n):
                    # Avoid self-loops
                    if src != mid and dst != mid:
                        new_t = dp[src][mid][0] + dp[mid][dst][0]

                        if new_t < dp[src][dst][0]:
                            # Found a shorter path
                            dp[src][dst][0] = new_t
                            dp[src][dst][1] = (dp[src][mid][1] * dp[mid][dst][1]) % self.MOD
                        elif new_t == dp[src][dst][0]:
                            # Another way to achieve the same shortest time
                            dp[src][dst][1] = (
                                dp[src][dst][1]
                                + dp[src][mid][1] * dp[mid][dst][1]
                            ) % self.MOD

        # Return the number of shortest paths from node (n - 1) to 0
        return dp[0][n - 1][1]
        