class Solution:
    def answer_query(self, graph: Dict[float, Dict[float, float]], start: int, end: int) -> int:
        if start not in graph:
            return -1
        
        seen = {start}
        stack = [(start, 1)]
        
        while stack:
            node, ratio = stack.pop()
            if node == end:
                return ratio
            
            for neighbor in graph[node]:
                if neighbor not in seen:
                    seen.add(neighbor)
                    stack.append((neighbor, ratio * graph[node][neighbor]))
        return -1
    
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        graph = defaultdict(dict)
        
        for i in range(len(equations)):
            numerator, denominator = equations[i]
            val = values[i]
            graph[numerator][denominator] = val
            graph[denominator][numerator] = 1 / val
        
        ans = []
        for numerator, denominator in queries:
            ans.append(self.answer_query(graph, numerator, denominator))
        
        return ans