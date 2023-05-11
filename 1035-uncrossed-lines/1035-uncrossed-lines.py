class Solution:
    def solve(self, i: int, j: int, nums1: List[int], nums2: List[int], memo: Dict[Tuple[int, int], int]) -> int:
        if i <= 0 or j <= 0:
            return 0
        
        if (i, j) in memo:
            return memo[(i, j)]
        
        if nums1[i - 1] == nums2[j - 1]:
            memo[(i, j)] = 1 + self.solve(i - 1, j - 1, nums1, nums2, memo)
        else:
            memo[(i, j)] = max(self.solve(i - 1, j, nums1, nums2, memo), self.solve(i, j - 1, nums1, nums2, memo))
        return memo[(i, j)]
        
    def maxUncrossedLines(self, nums1: List[int], nums2: List[int]) -> int:
        n1, n2 = len(nums1), len(nums2)
        memo = dict()
        
        return self.solve(n1, n2, nums1, nums2, memo)