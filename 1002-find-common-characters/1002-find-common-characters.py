class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        common, ans = [0] * 26, []
        
        for i_1 in range(len(words)):
            chars = [0] * 26
            for c in words[i_1]:
                chars[ord(c) - 97] += 1
            
            if i_1 > 0:
                for i_2 in range(26):
                    common[i_2] = min(common[i_2], chars[i_2])
            else:
                common = chars
        
        for i in range(26):
            for _ in range(common[i]):
                ans.append(chr(i + 97))
                
        return ans