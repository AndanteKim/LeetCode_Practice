class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        s_i, t_i = 0, 0
        
        while s_i < len(s) and t_i < len(t):
            if s[s_i] == t[t_i]:
                s_i += 1
                t_i += 1
            else:
                s_i += 1
        
        return len(t[t_i:])