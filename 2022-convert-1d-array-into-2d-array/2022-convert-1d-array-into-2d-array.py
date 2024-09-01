class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        # Base case
        if len(original) != m * n:
            return []
        
        ans = [[] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                ans[i].append(original[i * n + j])
                
        return ans