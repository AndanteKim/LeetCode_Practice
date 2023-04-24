class Solution:
    def bfs(self, boss: int, visited: List[bool], adj: List[List[int]], informTime) -> int:
        queue, total_time = deque([(boss, 0)]), 0
        
        while queue:
            current, time = queue.popleft()
            if not visited[current]:
                visited[current] = True
                for neighbor in adj[current]:
                    queue.append((neighbor, time + informTime[current]))
                total_time = max(total_time, time + informTime[current])
            
        return total_time
    
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        visited, ans = [False] * n, 0
        adj = [[] for _ in range(n)]
        
        for node in range(len(manager)):
            if manager[node] == -1:
                continue
            adj[manager[node]].append(node)
            
        ans = self.bfs(headID, visited, adj, informTime)
        return ans