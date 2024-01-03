class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        prev, ans = 0, 0
        
        for s in bank:
            cnt = 0
            
            for c in s:
                if c == '1':
                    cnt += 1
                
            if cnt != 0:
                ans += prev * cnt
                prev = cnt
                
                
        return ans