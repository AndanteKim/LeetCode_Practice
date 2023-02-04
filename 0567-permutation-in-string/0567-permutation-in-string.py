class Solution:
    def matches(self, s1: List[int], s2: List[int]) -> bool:
        for i in range(26):
            if s1[i] != s2[i]:
                return False
        return True
    
    def checkInclusion(self, s1: str, s2: str) -> bool:
        l1, l2 = len(s1), len(s2)
        
        if l1 > l2: return False
        
        dic_s1, dic_s2 = [0] * 26, [0] * 26
        for i in range(l1):
            dic_s1[ord(s1[i]) - ord('a')] += 1
            dic_s2[ord(s2[i]) - ord('a')] += 1
        
        for i in range(l2 - l1):
            if self.matches(dic_s1, dic_s2): return True
            
            dic_s2[ord(s2[i + l1]) - ord('a')] += 1
            dic_s2[ord(s2[i]) - ord('a')] -= 1
        
        return self.matches(dic_s1, dic_s2)