class Solution:
    
    def confusingNumberII(self, n: int) -> int:
        lookup = {0:0, 1:1, 6:9, 8:8, 9:6}
        
        self.count = 0
        
        def dfs(num: int, numRotated: int, unit: int) -> None:
            
            if num != numRotated:
                self.count += 1
            
            for d, dRotate in lookup.items():
                if d == 0 and num == 0:
                    continue
                if num * 10 + d > n:
                    break
                dfs(num * 10 + d, dRotate * unit + numRotated, unit * 10)
        
        dfs(0, 0, 1)
        
        return self.count
        