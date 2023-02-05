class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        
        table_p, len_p = [0] * 26, len(p)
        for c in p:
            table_p[ord(c) - ord('a')] += 1
            
        table_s, ans, left = [0] * 26, [], 0
        for right in range(len(s)):
            
            if table_s[ord(s[right]) - ord('a')] < table_p[ord(s[right]) - ord('a')]:
                table_s[ord(s[right]) - ord('a')] += 1
            else:
                while left < right and table_s[ord(s[right]) - ord('a')] >= table_p[ord(s[right]) - ord('a')]:
                    if table_s[ord(s[left]) - ord('a')] > 0:
                        table_s[ord(s[left]) - ord('a')] -= 1
                    left += 1
                
                if table_p[ord(s[right]) - ord('a')] > 0:
                    table_s[ord(s[right]) - ord('a')] += 1
            
            if table_s == table_p:
                ans.append(right + 1 - len_p)
                
        return ans