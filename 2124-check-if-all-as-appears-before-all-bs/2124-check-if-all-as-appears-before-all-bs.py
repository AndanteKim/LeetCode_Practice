class Solution:
    def checkString(self, s: str) -> bool:
        n, a_last = len(s), -1
        b_first = n

        for i in range(n):
            if s[i] == 'a':
                a_last = i
            else:
                b_first = min(b_first, i)

        return a_last < b_first