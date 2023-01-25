class Solution:
    def dfs(self, node: int, edges: List[int], dist: List[int], visit: List[bool]) -> None:
        visit[node] = True
        neighbor = edges[node]
        
        if neighbor != -1 and not visit[neighbor]:
            dist[neighbor] = 1 + dist[node]
            self.dfs(neighbor, edges, dist, visit)
        
        

    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        n = len(edges)
        dist1, dist2 = [float('inf')] * n, [float('inf')] * n
        visit1, visit2 = [False] * n, [False] * n
        dist1[node1], dist2[node2] = 0, 0
        
        self.dfs(node1, edges, dist1, visit1)
        self.dfs(node2, edges, dist2, visit2)
        
        minDistNode, minDistTillNow = -1, float('inf')
        
        for currNode in range(n):
            if (minDistTillNow > max(dist1[currNode], dist2[currNode])):
                minDistNode = currNode
                minDistTillNow = max(dist1[currNode], dist2[currNode])
        
        return minDistNode
        