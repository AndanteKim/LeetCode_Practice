class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        ans = ['a'] * n
        for pos in range(n - 1, -1, -1):
            add = min(k - pos, 26)
            ans[pos] = chr(add + ord('a') - 1)
            k -= add
        
        return "".join(ans)