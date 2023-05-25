class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        ans = 0
        g.sort()
        s.sort()
        g_i, s_i = 0, 0
        
        while g_i < len(g) and s_i < len(s):
            if g[g_i] <= s[s_i]:
                ans += 1
                g_i += 1
                s_i += 1
            else:
                s_i += 1
        return ans