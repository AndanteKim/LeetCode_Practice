class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        RED, BLUE = 0, 1
        graph = defaultdict(lambda: defaultdict(list))
        
        for start, end in redEdges:
            graph[RED][start].append(end)
        
        for start, end in blueEdges:
            graph[BLUE][start].append(end)
            
        ans = [float("inf")] * n
        queue = deque([(0, RED, 0), (0, BLUE, 0)])
        seen = {(0, RED), (0, BLUE)}
        
        while queue:
            node, color, steps = queue.popleft()
            ans[node] = min(ans[node], steps)
        
            for neighbor in graph[color][node]:
                if (neighbor, 1 - color) not in seen:
                    seen.add((neighbor, 1 - color))
                    queue.append((neighbor, 1 - color, steps + 1))
        
        return [x if x != float("inf") else -1 for x in ans]