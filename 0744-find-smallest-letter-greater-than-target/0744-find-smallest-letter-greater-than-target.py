class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        alphabets = [0] * 26
        ans = letters[0]
        for letter in letters:
            alphabets[ord(letter) - ord('a')] += 1
        
        for i in range(ord(target) - ord('a') + 1, 26):
            if alphabets[i] != 0:
                return chr(i + 97)
            
        return ans