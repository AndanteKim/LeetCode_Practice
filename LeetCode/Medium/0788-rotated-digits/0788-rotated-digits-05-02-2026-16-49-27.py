class Solution:
    def rotatedDigits(self, n: int) -> int:
        ans, changeable, invalid = 0, [2, 5, 6, 9], [3, 4, 7]
        for i in range(1, n + 1):
            S = str(i)

            ans += (all(d not in '347' for d in S) and any(d in '2569' for d in S))

        return ans