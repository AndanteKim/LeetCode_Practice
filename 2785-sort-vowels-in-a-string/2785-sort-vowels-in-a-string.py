class Solution:
    def sortVowels(self, s: str) -> str:
        vowels, curr, ans = {'A':0, 'E':0, 'I':0, 'O':0, 'U':0, 'a':0, 'e':0, 'i':0, 'o':0, 'u':0}, [], ""
        
        for c in s:
            if c in vowels:
                vowels[c] += 1
        for char, val in vowels.items():
            if val > 0:
                heappush(curr, (char, val))
        
        for c in s:
            if c in vowels:
                vowel, val = heappop(curr)
                ans += vowel
                val -= 1
                if val > 0:
                    heappush(curr, (vowel, val))
                
            else:
                ans += c
        
        return ans
        