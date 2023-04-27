class Solution:
    def bulbSwitch(self, n: int) -> int:
        if n <= 1:
            return n
        
        return int(n ** 0.5)