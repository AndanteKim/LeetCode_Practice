class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        
        curr, sign = 1, 1
        while time > 0:
            # Pass the pillow
            curr += sign
            
            if curr == 1 or curr == n:
                sign *= -1
            
            time -= 1
            
        return curr