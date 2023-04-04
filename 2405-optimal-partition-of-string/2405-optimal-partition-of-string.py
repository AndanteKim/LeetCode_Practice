class Solution:
    def partitionString(self, s: str) -> int:
        lastSeen = [-1] * 26
        count, substrStart = 1, 0
        
        for i in range(len(s)):
            if lastSeen[ord(s[i]) - ord('a')] >= substrStart:
                count += 1
                substrStart = i
            lastSeen[ord(s[i]) - ord('a')] = i
        
        return count