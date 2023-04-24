class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        connected = defaultdict(set)
        
        for start, end in roads:
            connected[start].add(end)
            connected[end].add(start)
        
        ans = 0
        for i in range(n):
            for j in range(i + 1, n):
                ans = max(ans, len(connected[i]) + len(connected[j]) - (i in connected[j]))
        
        return ans