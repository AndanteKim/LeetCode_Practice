class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        ans, freq, overlap = [0] * n, [0] * (n + 1), 0

        for i in range(n):
            freq[A[i]] += 1

            if freq[A[i]] == 2:
                overlap += 1

            freq[B[i]] += 1           
            if freq[B[i]] == 2:
                overlap += 1

            ans[i] = overlap

        return ans