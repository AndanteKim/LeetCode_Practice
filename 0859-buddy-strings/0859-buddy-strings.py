class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        
        if s == goal:
            freq = [0] * 26
            for c in s:
                freq[ord(c) - ord('a')] += 1
                if freq[ord(c) - ord('a')] == 2:
                    return True
            return False
        
        firstIdx, secondIdx = -1, -1
        
        for i in range(len(s)):
            if s[i] != goal[i]:
                if firstIdx == -1:
                    firstIdx = i
                elif secondIdx == -1:
                    secondIdx = i
                else:
                    return False
        
        if secondIdx == -1:
            return False
        
        return s[firstIdx] == goal[secondIdx] and s[secondIdx] == goal[firstIdx]