class Solution:
    def minimumSemesters(self, n: int, relations: List[List[int]]) -> int:
        graph = {i: [] for i in range(1, n + 1)}
        indegree = {i: 0 for i in range(1, n + 1)}
        
        for prev, nxt in relations:
            graph[prev].append(nxt)
            indegree[nxt] += 1
        
        queue = []
        # We use list here since we are not poping from
        # front this code
        for node in graph:
            if indegree[node] == 0:
                queue.append(node)
        
        step, semesters = 0, 0
        
        # start learning with BFS
        while queue:
            step += 1
            next_queue = []
            for node in queue:
                semesters += 1
                end_nodes = graph[node]
                for end_node in end_nodes:
                    indegree[end_node] -= 1
                    
                    # if all prerequisite courses learned
                    if indegree[end_node] == 0:
                        next_queue.append(end_node)
            queue = next_queue
        
        return step if semesters == n else -1