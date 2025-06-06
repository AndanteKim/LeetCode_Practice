class Solution:
    def robotWithString(self, s: str) -> str:
        ans, n = "", len(s)
        suffixMin = [None] * n
        
        for i in range(n-1, -1, -1):
            if i == n - 1:
                suffixMin[i] = s[i]
            else:
                suffixMin[i] = min(s[i], suffixMin[i+1])
        
        t = []
        for i in range(n):
            t.append(s[i])
            
            while t and (i == n - 1 or t[-1] <= suffixMin[i+1]):
                ans += t.pop()
        
        return ans