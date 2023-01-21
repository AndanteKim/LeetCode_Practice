class Solution:
    def valid(self, s: str, start: int, length: int) -> bool:
        return length == 1 or (s[start] != '0' and (length < 3 or s[start:start+length] <= "255"))
    
    def restoreIpAddresses(self, s: str) -> List[str]:
        ans, length = [], len(s)
        
        for len1 in range(max(1, length - 9), min(3, length - 3)+1):
            if not self.valid(s, 0, len1):
                continue
                
            for len2 in range(max(1, length - len1 - 6), min(3, length - len1 - 2)+1):
                if not self.valid(s, len1, len2):
                    continue
                for len3 in range(max(1, length - len1 - len2 - 3), min(3, length - len1 - len2 - 1)+1):
                    if self.valid(s, len1 + len2, len3) and self.valid(s, len1 + len2 + len3, length - len1 - len2 - len3):
                        ans.append(s[0:len1] + '.' + s[len1:len1+len2] + '.' + s[len1 + len2:len1 + len2 + len3] + '.' + s[len1 + len2 + len3:])
        
        
        return ans