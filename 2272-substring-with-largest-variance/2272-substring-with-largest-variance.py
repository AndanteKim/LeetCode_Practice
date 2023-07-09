class Solution:
    def largestVariance(self, s: str) -> int:
        counter = [0] * 26
        for c in s:
            counter[ord(c) - 97] += 1
        
        global_max = 0
        
        for i in range(26):
            for j in range(26):
                if i == j or counter[i] == 0 or counter[j] == 0:
                    continue
                
                major, minor = chr(97 + i), chr(97 + j)
                major_count, minor_count = 0, 0
                
                rest_minor = counter[j]
                for c in s:
                    if c == major:
                        major_count += 1
                    if c == minor:
                        minor_count += 1
                        rest_minor -= 1
                    
                    if minor_count > 0:
                        global_max = max(global_max, major_count - minor_count)
                    
                    if major_count < minor_count and rest_minor > 0:
                        major_count, minor_count = 0, 0
        
        return global_max
                        