class Solution:
    def backtrack(self, curr_node: float, target_node: float, acc_product: float, visited: Set[float], graph: DefaultDict[str, DefaultDict[str, float]]) -> float:
        visited.add(curr_node)
        res = -1.0
        neighbors = graph[curr_node]
        if target_node in neighbors:
            res = acc_product * neighbors[target_node]
        else:
            for neighbor, val in neighbors.items():
                if neighbor in visited:
                    continue
                res = self.backtrack(neighbor, target_node, acc_product * val, visited, graph)
                if res != -1.0:
                    break
        visited.remove(curr_node)
        return res
    
    
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        graph = defaultdict(defaultdict)
        
        # step 1: build the graph from the equations
        for (dividend, divisor), value in zip(equations, values):
            # add nodes and two edges into the graph
            graph[dividend][divisor] = value
            graph[divisor][dividend] = 1 / value
            
        # step 2: evaluate each query via dfs by verifying
        # if there exists a path from dividend to divisor
        ans = []
        for dividend, divisor in queries:
            if dividend not in graph or divisor not in graph:
                # case 1: either node doesn't exist
                res = -1.0
            elif dividend == divisor:
                # case 2: origin and destination are the same node
                res = 1.0
            else:
                visited = set()
                res = self.backtrack(dividend, divisor, 1, visited, graph)
            ans.append(res)
        
        return ans
        