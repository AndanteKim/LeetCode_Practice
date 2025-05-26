class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        n = len(colors)
        adj = defaultdict(list)
        indegree = [0] * n

        for u, v in edges:
            adj[u].append(v)
            indegree[v] += 1
        
        count = [[0] * 26 for _ in range(n)]
        q = deque()

        # Push all the nodes with indegree zero in the queue.
        for i in range(n):
            if indegree[i] == 0:
                q.append(i)

        ans, nodes_seen = 0, 0
        while q:
            node = q.popleft()
            count[node][ord(colors[node]) - 97] += 1
            ans = max(ans, count[node][ord(colors[node]) - 97])
            nodes_seen += 1

            for neighbor in adj[node]:
                for i in range(26):
                    # Try to update the frequency of colors for neighbor to include paths
                    # that use node -> neighbor edge.
                    count[neighbor][i] = max(count[neighbor][i], count[node][i])
                
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    q.append(neighbor)

        return -1 if nodes_seen < n else ans
