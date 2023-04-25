class Solution:
    def dfs(self, node: int, colored: int, color: List[int], graph: List[List[int]]) -> None:
        if color[node] == -1:
            color[node] = colored
            for neighbor in graph[node]:
                self.dfs(neighbor, colored, color, graph)
    
    def equationsPossible(self, equations: List[str]) -> bool:
        graph = [[] for _ in range(26)]
        
        for equation in equations:
            if equation[1] == '=':
                x = ord(equation[0]) - ord('a')
                y = ord(equation[3]) - ord('a')
                graph[x].append(y)
                graph[y].append(x)
        
        color = [-1] * 26
        
        for i in range(26):
            if color[i] == -1:
                self.dfs(i, i, color, graph)
                
        for equation in equations:
            if equation[1] == '!':
                x = ord(equation[0]) - ord('a')
                y = ord(equation[3]) - ord('a')
                if color[x] == color[y]:
                    return False
            
        return True