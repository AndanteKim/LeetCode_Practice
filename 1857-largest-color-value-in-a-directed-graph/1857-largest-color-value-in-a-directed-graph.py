class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        n = len(colors)
        adj, indegree = [[] for _ in range(n)], [0] * n
        
        for start, end in edges:
            adj[start].append(end)
            indegree[end] += 1
        
        count_sort = [[0] * 26 for _ in range(n)]
        queue = deque()
        
        for i in range(n):
            if indegree[i] == 0:
                queue.append(i)
        
        answer, nodesSeen = 0, 0
        while queue:
            node = queue.popleft()
            count_sort[node][ord(colors[node]) - ord('a')] += 1
            answer = max(answer, count_sort[node][ord(colors[node]) - ord('a')])
            nodesSeen += 1
            
            for neighbor in adj[node]:
                for i in range(26):
                    count_sort[neighbor][i] = max(count_sort[neighbor][i], count_sort[node][i])
                
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    queue.append(neighbor)
        return -1 if nodesSeen < n else answer