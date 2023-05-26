class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        ans = [0] * n
        
        for pos_left in range(n):
            pos_right = n - pos_left - 1
            if k > pos_right * 26:
                add = k - (pos_right * 26)
                ans[pos_left] = chr(97 + add - 1)
                k -= add
            else:
                ans[pos_left] = 'a'
                k -= 1
                
        return "".join(ans)