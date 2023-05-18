class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        visited = [False] * n
        
        for start, end in edges:
            visited[end] = True
        
        ans = []
        for node in range(n):
            if not visited[node]:
                ans.append(node)
        
        return ans