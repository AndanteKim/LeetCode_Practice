class Solution:
    
    def checkInclusion(self, s1: str, s2: str) -> bool:
        l1, l2 = len(s1), len(s2)
        
        if l1 > l2: return False
        
        dic_s1, dic_s2 = [0] * 26, [0] * 26
        for i in range(l1):
            dic_s1[ord(s1[i]) - ord('a')] += 1
            dic_s2[ord(s2[i]) - ord('a')] += 1
        
        cnt = 0
        for i in range(26):
            if dic_s1[i] == dic_s2[i]:
                cnt += 1
                
        for i in range(l2 - l1):
            right, left = ord(s2[i + l1]) - ord('a'), ord(s2[i]) - ord('a')
            
            if cnt == 26:
                return True
            
            dic_s2[right] += 1
            if (dic_s2[right] == dic_s1[right]): cnt += 1
            elif (dic_s2[right] == dic_s1[right] + 1): cnt -= 1
            
            dic_s2[left] -= 1
            if (dic_s2[left] == dic_s1[left]): cnt += 1
            elif (dic_s2[left] == dic_s1[left] - 1): cnt -= 1
        
        return cnt == 26