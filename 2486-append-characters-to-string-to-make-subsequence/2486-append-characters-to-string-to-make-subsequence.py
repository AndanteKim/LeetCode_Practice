class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        s_i, t_i = 0, 0
        s_len, t_len = len(s), len(t)
        
        while s_i < s_len and t_i < t_len:
            if s[s_i] == t[t_i]:
                s_i += 1
                t_i += 1
            else:
                s_i += 1
        
        return t_len - t_i