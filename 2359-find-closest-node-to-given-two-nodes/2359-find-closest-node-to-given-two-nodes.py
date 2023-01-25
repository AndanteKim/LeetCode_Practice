class Solution:
    def bfs(self, startNode: int, edges: int, dist: List[int]) -> None:
        n = len(edges)
        q = deque([startNode])
        
        visit = [False] * n
        dist[startNode] = 0
        
        while q:
            node = q.popleft()
            
            if visit[node]:
                continue
                
            visit[node] = True
            neighbor = edges[node]
            if neighbor != -1 and not visit[neighbor]:
                dist[neighbor] = 1 + dist[node]
                q.append(neighbor)
        

    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        n = len(edges)
        dist1, dist2 = [float('inf')] * n, [float('inf')] * n
        
        self.bfs(node1, edges, dist1)
        self.bfs(node2, edges, dist2)
        
        minDistNode, minDistTillNow = -1, float('inf')
        
        for currNode in range(n):
            if (minDistTillNow > max(dist1[currNode], dist2[currNode])):
                minDistNode = currNode
                minDistTillNow = max(dist1[currNode], dist2[currNode])
        
        return minDistNode
        