class Solution:
    
    def confusingNumberII(self, n: int) -> int:
        valid = [0,1,6,8,9]
        lookup = {0:0, 1:1, 6:9, 8:8, 9:6}
        
        self.count = 0

        def backtrack(v: int, rotation: int, digits: int) -> None:
            if v:
                if v != rotation:
                    self.count += 1
            
            for i in valid:
                if v * 10 + i > n:
                    break
                else:
                    backtrack(v * 10 + i, lookup[i] * digits + rotation, digits * 10)
        backtrack(1, 1, 10)
        backtrack(6, 9, 10)
        backtrack(8, 8, 10)
        backtrack(9, 6, 10)
        
        return self.count
        