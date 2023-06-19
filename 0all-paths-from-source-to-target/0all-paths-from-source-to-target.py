class Solution:
    def backtrack(self, start: int, curr: List[int], graph: List[List[int]], ans: List[List[int]]) -> None:
        if start == len(graph) - 1:
            ans.append(curr[:])
            return
        
        for n1 in graph[start]:
            curr.append(n1)
            self.backtrack(n1, curr, graph, ans)
            curr.pop()
    
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        ans = []
        self.backtrack(0, [0], graph, ans)
        return ans