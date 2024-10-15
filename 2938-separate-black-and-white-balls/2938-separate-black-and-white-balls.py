class Solution:
    def minimumSteps(self, s: str) -> int:
        ans, black = 0, 0
        
        # Iterate through each ball in the string
        for c in s:
            if c == '0':
                ans += black
            else:
                black += 1
                
        return ans