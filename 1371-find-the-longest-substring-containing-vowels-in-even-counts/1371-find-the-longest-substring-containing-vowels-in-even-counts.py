class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        prefixXOR = 0
        char_map = [0] * 26
        char_map[ord('a') - 97] = 1
        char_map[ord('e') - 97] = 2
        char_map[ord('i') - 97] = 4
        char_map[ord('o') - 97] = 8
        char_map[ord('u') - 97] = 16
        
        # If all vowels are odd, then max of mp size would be 31.
        mp, ans = [-1] * 32, 0
        
        for i in range(len(s)):
            prefixXOR ^= char_map[ord(s[i]) - 97]
            if mp[prefixXOR] == -1 and prefixXOR != 0:
                mp[prefixXOR] = i
                
            ans = max(ans, i - mp[prefixXOR])
            
        return ans