class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        ans, setA, setB = [0] * n, set(), set()

        for i in range(n):
            setA.add(A[i])
            setB.add(B[i])

            ans[i] = len(setA.intersection(setB))
        
        return ans

        