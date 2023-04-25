class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        adj = [[] for _ in range(n)]
        indegrees = [0] * n
        
        for start, end in edges:
            adj[start].append(end)
            indegrees[end] += 1
        
        queue = deque()
        ans = [set() for _ in range(n)]
        for i in range(len(indegrees)):
            if indegrees[i] == 0:
                queue.append(i)
        
        while queue:
            curr = queue.popleft()
            
            for neighbor in adj[curr]:
                ans[neighbor].add(curr)
                ans[neighbor].update(ans[curr])
                indegrees[neighbor] -= 1
                if indegrees[neighbor] == 0:
                    queue.append(neighbor)
        
        ans = [(sorted(list(s))) for s in ans]
        return ans
        