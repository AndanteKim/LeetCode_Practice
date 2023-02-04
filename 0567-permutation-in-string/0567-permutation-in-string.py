class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        sort_s1 = [c for c in s1]
        sort_s1.sort()
        
        sort_s2 = [c for c in s2]
        
        l1, l2 = len(s1), len(s2)
        for i in range(l2 - l1 + 1):
            if sort_s1 == sorted(sort_s2[i:i+l1]):
                return True
        
        return False