class Solution:
    def countSeniors(self, details: List[str]) -> int:
        ans = 0
        
        for d in details:
            if d[11] in ('7', '8', '9'):
                ans += 1
            elif d[11] == '6' and d[12] != '0':
                ans += 1
                
        return ans
