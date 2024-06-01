class Solution:
    def longestCommonSubsequence(self, arrays: List[List[int]]) -> List[int]:
        intersect, rows, ans = [0] * 101, len(arrays), []
        
        for arr in arrays:
            for num in arr:
                intersect[num] += 1
        
        for i in range(1, 101):
            if intersect[i] == rows:
                ans.append(i)
                
        return ans