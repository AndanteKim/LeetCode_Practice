class Solution:
    def longestBalanced(self, s: str) -> int:
        n = len(s)

        ans, length = 1, 1
        # Deal with 1 letter balance
        for c0, c1 in pairwise(s):
            if c0 == c1:
                length += 1
            else:
                ans = max(ans, length)
                length = 1
            
        ans = max(ans, length)

        ab, bc, ca, abc = dict(), dict(), dict(), dict()
        ab[(0, 0)] = bc[(0, 0)] = ca[(0, 0)] = abc[(0, 0)] = -1
        counts = [0, 0, 0]

        for i, c in enumerate(s):
            counts[ord(c) - 97] += 1
            A, B, C = counts

            # 3 letter case
            key = (B - A, C - A)
            if key in abc:
                ans = max(ans, i - abc[key])
            else:
                abc[key] = i

            # 2 letter case
            key = (A - B, C)
            if key in ab:
                ans = max(ans, i - ab[key])
            else:
                ab[key] = i

            key = (B - C, A)
            if key in bc:
                ans = max(ans, i - bc[key])
            else:
                bc[key] = i
            
            key = (C - A, B)
            if key in ca:
                ans = max(ans, i - ca[key])
            else:
                ca[key] = i

        return ans
        