class Solution:
    def bfs(self, n: int, adj: List[List[int]]) -> int:
        visit = [False] * (n + 1)
        queue = deque([1])
        answer = float('inf')
        visit[1] = True
        
        while queue:
            node = queue.popleft()
            for edge in adj[node]:
                answer = min(answer, edge[1])
                if not visit[edge[0]]:
                    visit[edge[0]] = True
                    queue.append(edge[0])
        return answer
    
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        adj = [[] for i in range(n+1)]
        
        for road in roads:
            adj[road[0]].append([road[1], road[2]])
            adj[road[1]].append([road[0], road[2]])
        print(adj)
        return self.bfs(n, adj)