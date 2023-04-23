class Solution:   
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        if roads == []:
            return 0
        adj, ans = [[] for _ in range(n)], 0
        
        for start, end in roads:
            adj[start].append(end)
            adj[end].append(start)
        
        for i in range(n - 1):
            node1 = i
            for j in range(i + 1, n):
                node2 = j
                if [node1, node2] in roads or [node2, node1] in roads:
                    ans = max(ans, len(adj[node1]) + len(adj[node2]) - 1)
                else:
                    ans = max(ans, len(adj[node1]) + len(adj[node2]))
        return ans