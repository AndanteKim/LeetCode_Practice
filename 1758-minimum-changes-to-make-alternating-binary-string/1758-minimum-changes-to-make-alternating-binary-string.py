class Solution:
    def minOperations(self, s: str) -> int:
        pattern, changes_0_1, changes_1_0 = ['1', '0'], 0, 0
        
        for i in range(len(s)):
            if pattern[i % 2] == s[i]:
                changes_1_0 += 1
            else:
                changes_0_1 += 1
            
        return min(changes_0_1, changes_1_0)