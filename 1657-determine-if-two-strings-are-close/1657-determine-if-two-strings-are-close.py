class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        count1, count2 = [0] * 26, [0] * 26
        
        for c in word1:
            count1[ord(c) - 97] += 1
        for c in word2:
            if count1[ord(c) - 97] == 0:
                return False
            count2[ord(c) - 97] += 1
        
        count1.sort(reverse = True)
        count2.sort(reverse = True)
        
        for i in range(26):
            if count1[i] != count2[i]:
                return False
        return True