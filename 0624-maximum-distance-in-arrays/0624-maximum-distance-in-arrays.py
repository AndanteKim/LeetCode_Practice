class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        ans = 0
        n, min_val, max_val = len(arrays[0]), arrays[0][0], arrays[0][len(arrays[0]) - 1]
        
        for i in range(1, len(arrays)):
            n = len(arrays[i])
            ans = max(ans, abs(arrays[i][n - 1] - min_val), abs(max_val - arrays[i][0]))
            min_val = min(min_val, arrays[i][0])
            max_val = max(max_val, arrays[i][n - 1])
        
        return ans
        
        