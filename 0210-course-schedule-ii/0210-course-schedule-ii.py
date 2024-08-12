class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(numCourses)]
        indegree = [0] * numCourses
        
        for end, start in prerequisites:
            indegree[end] += 1
            adj[start].append(end)
            
        queue = deque()
        
        for i in range(numCourses):
            if indegree[i] == 0:
                queue.append(i)
        
        ans = []
        while queue:
            curr = queue.popleft()
            ans.append(curr)
            
            for neighbor in adj[curr]:
                indegree[neighbor] -= 1
                
                if indegree[neighbor] == 0:
                    queue.append(neighbor)
                
                
        return ans if len(ans) == numCourses else []