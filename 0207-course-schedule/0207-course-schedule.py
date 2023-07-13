class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        indegree = [0] * numCourses
        adj = [[] for _ in range(numCourses)]
        
        for nxt, need in prerequisites:
            adj[need].append(nxt)
            indegree[nxt] += 1
        
        queue = deque()
        for i in range(numCourses):
            if indegree[i] == 0:
                queue.append(i)
                
        nodesVisited = 0
        while queue:
            node = queue.popleft()
            nodesVisited += 1
            
            for neighbor in adj[node]:
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    queue.append(neighbor)
        
        return nodesVisited == numCourses