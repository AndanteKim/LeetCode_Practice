class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        # Topological sort and Khan algorithm
        adj = [[] for _ in range(numCourses)]
        indegree = [0] * numCourses

        for edge in prerequisites:
            adj[edge[0]].append(edge[1])
            indegree[edge[1]] += 1
        
        q = deque()
        for i in range(numCourses):
            if indegree[i] == 0:
                q.append(i)

        node_prerequisites = defaultdict(set)

        while q:
            node = q.popleft()

            for neighbor in adj[node]:
                # Add node and prerequisite o f the node to the prerequisites of adj
                node_prerequisites[neighbor].add(node)

                for prerequisite in node_prerequisites[node]:
                    node_prerequisites[neighbor].add(prerequisite)
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    q.append(neighbor)
        
        ans = []
        for start, end in queries:
            ans.append(start in node_prerequisites[end])

        return ans