class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        indegree = [0 for _ in range(n)]
        
        for start, end in edges:
            indegree[end] += 1
        
        ans, mn = [], min(indegree)
        for node in range(len(indegree)):
            if indegree[node] == mn:
                ans.append(node)
        return ans
        