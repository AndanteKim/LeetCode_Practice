class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        color = dict()
        for node in range(len(graph)):
            if node not in color:
                stack = [node]
                color[node] = 0
                
                while stack:
                    node = stack.pop()
                    for neighbor in graph[node]:
                        if neighbor not in color:
                            stack.append(neighbor)
                            color[neighbor] = color[node] ^ 1
                        elif color[neighbor] == color[node]:
                            return False
        return True