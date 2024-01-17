class Solution:
    def calculateTime(self, keyboard: str, word: str) -> int:
        ans, prev = 0, 0
        keyboard_idx = dict()
        
        for i, ch in enumerate(keyboard):
            keyboard_idx[ch] = i
        
        for c in word:
            ans += abs(keyboard_idx[c] - prev)
            prev = keyboard_idx[c]
            
        return ans
        