class Solution:
    def countPalindromesAroundCenter(self, ss: str, lo: int, hi: int) -> int:
        ans = 0
        
        while lo >= 0 and hi < len(ss):
            if ss[lo] != ss[hi]:
                break
                
            # expand around the center
            lo -= 1
            hi += 1
            
            ans += 1
        return ans
    
    def countSubstrings(self, s: str) -> int:
        ans = 0
        
        for i in range(len(s)):
            # odd-length palindromes, single character center
            ans += self.countPalindromesAroundCenter(s, i, i)
            
            # even-length palindromes, consecutive characters center
            ans += self.countPalindromesAroundCenter(s, i, i + 1)
            
        return ans
    
    
            