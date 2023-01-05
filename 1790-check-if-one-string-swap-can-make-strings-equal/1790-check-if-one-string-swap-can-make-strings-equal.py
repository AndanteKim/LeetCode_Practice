class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        
        if s1 == s2: return True
        c1, c2, cnt = Counter(s1), Counter(s2), 0
        
        for i in range(len(s1)):
            cnt += s1[i] != s2[i]
            if cnt > 2:
                return False
            if c1[s1[i]] != c2[s1[i]]:
                return False
        return True
    