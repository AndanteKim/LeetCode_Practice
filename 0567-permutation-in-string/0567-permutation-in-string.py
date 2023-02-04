class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        l1, l2 = len(s1), len(s2)
        
        if l1 > l2: return False
        
        dic_s1 = defaultdict(int)
        
        for c in s1:
            dic_s1[c] += 1
        
        for i in range(l2 - l1 + 1):
            dic_s2 = defaultdict(int)
            
            for j in range(l1):
                dic_s2[s2[i+j]] += 1
            if dic_s1 == dic_s2:
                return True
        return False