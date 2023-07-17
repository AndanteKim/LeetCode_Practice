class Solution:
    def maxUncrossedLines(self, nums1: List[int], nums2: List[int]) -> int:
        n1, n2 = len(nums1), len(nums2)
        memo = dict()
        
        def solve(i: int, j: int) -> int:
            if i <= 0 or j <= 0:
                return 0
            
            if (i, j) in memo:
                return memo[(i, j)]
            
            if nums1[i - 1] == nums2[j - 1]:
                memo[(i, j)] = 1 + solve(i - 1, j - 1)
            else:
                memo[(i, j)] = max(solve(i - 1, j), solve(i, j - 1))
            return memo[(i, j)]
        
        return solve(n1, n2)