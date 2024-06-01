class Solution:
    def longestCommonSubsequence(self, arrays: List[List[int]]) -> List[int]:
        intersect = set(arrays[0])
        
        for arr in arrays[1:]:
            intersect = intersect.intersection(set(arr))
                
        return sorted(list(intersect))