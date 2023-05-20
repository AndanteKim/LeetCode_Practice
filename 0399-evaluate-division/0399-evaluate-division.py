class Solution:
    def backtrack_evaluate(self, curr_node: str, target_node: str, acc_product: float, visited: Set[str], graph: Dict[str, Dict[str, float]]) -> float:
        visited.add(curr_node)
        ret = -1.0
        neighbors = graph[curr_node]
        if target_node in neighbors:
            ret = acc_product * neighbors[target_node]
        else:
            for neighbor, value in neighbors.items():
                if neighbor in visited:
                    continue
                ret = self.backtrack_evaluate(neighbor, target_node, acc_product * value, visited, graph)
                if ret != -1.0:
                    break
        visited.remove(curr_node)
        return ret
    
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        graph = defaultdict(defaultdict)
        
        for (dividend, divisor), value in zip(equations, values):
            graph[dividend][divisor] = value
            graph[divisor][dividend] = 1 / value
        
        ans = []
        
        for dividend, divisor in queries:
            if dividend not in graph or divisor not in graph:
                ret = -1.0
            elif dividend == divisor:
                ret = 1.0
            else:
                visited = set()
                ret = self.backtrack_evaluate(dividend, divisor, 1, visited, graph)
            ans.append(ret)
        
        return ans