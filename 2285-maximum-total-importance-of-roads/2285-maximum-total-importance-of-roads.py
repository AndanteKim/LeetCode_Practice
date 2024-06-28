class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        degree = [0] * n
        
        for edge in roads:
            degree[edge[0]] += 1
            degree[edge[1]] += 1
            
        degree.sort()
        
        val, total_importance = 1, 0
        
        for d in degree:
            total_importance += val * d
            val += 1
        
        return total_importance