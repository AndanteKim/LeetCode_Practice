class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        n, i, remain = len(s), 0, 1

        while i < n:
            if s[i] == '1':
                if remain == 0:
                    return False
                remain -= 1
                while i < n and s[i] == '1':
                    i += 1
            i += 1

        return True