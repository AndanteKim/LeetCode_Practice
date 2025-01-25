class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)
        adj, indegree = [[] for _ in range(n)], [0] * n

        for start in range(n):
            for end in graph[start]:
                adj[end].append(start)
                indegree[start] += 1

        q = deque()

        # Push all the nodes with indegree zero in the queue
        for node in range(n):
            if indegree[node] == 0:
                q.append(node)

        safe = [False] * n

        while q:
            node = q.popleft()
            safe[node] = True

            for neighbor in adj[node]:
                # Delete the edge "node -> neighbor".
                indegree[neighbor] -= 1

                if indegree[neighbor] == 0:
                    q.append(neighbor)

        ans = []
        for node in range(n):
            if safe[node]:
                ans.append(node)

        return ans       