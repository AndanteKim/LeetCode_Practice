class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        ans = ['a'] * n
        k -= n
        
        for pos in range(n - 1, -1, -1):
            if k <= 0:
                break
            add = min(k, 25)
            ans[pos] = chr(ord(ans[pos]) + add)
            k -= add
        return "".join(ans)