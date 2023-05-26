class Solution:
    def partitionString(self, s: str) -> int:
        substr, ans = [0] * 26, 1
        for c in s:
            if substr[ord(c) - 97] & 1:
                ans += 1
                substr = [0] * 26
                substr[ord(c) - 97] += 1
            else:
                substr[ord(c) - 97] += 1
            
        return ans