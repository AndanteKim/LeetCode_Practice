class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        
        left, max_len, curr, changed = 0, 0, 0, 0
        
        for right in range(len(s)):
            right_cost = abs(ord(s[right]) - ord(t[right]))
            
            if curr + right_cost <= maxCost:
                curr += right_cost
                changed += 1
            else:
                
                while left < right:
                    left_cost = abs(ord(s[left]) - ord(t[left]))
                    if left_cost <= maxCost:
                        curr -= left_cost
                        changed -= 1
                    left += 1
                    if curr + right_cost <= maxCost:
                        curr += right_cost
                        changed += 1
                        break
            
            max_len = max(max_len, changed)
            
            
        
        return max_len