class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        counter_s = Counter(s)
        
        for ch in t:
            if ch not in counter_s or counter_s[ch] == 0:
                return ch
            else:
                counter_s[ch] -= 1