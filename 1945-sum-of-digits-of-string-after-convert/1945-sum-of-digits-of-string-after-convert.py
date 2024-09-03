class Solution:
    def getLucky(self, s: str, k: int) -> int:
        convert_s = ""
        
        for c in s:
            convert_s += str(ord(c) - 96)
            
        transform, s = 0, convert_s
        for _ in range(k):
            transform = 0
            for c in s:
                transform += int(c)
                
            s = str(transform)
            
        return transform