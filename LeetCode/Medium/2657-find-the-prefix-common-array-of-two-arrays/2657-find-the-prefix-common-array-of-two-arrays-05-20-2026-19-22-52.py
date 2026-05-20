class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n, sa, sb = len(A), set(), set()
        ans = [0] * n

        for i in range(n):
            sa.add(A[i])
            sb.add(B[i])
            ans[i] = len(sa.intersection(sb))

        return ans