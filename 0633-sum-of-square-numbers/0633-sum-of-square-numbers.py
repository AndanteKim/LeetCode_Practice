class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        # s:= start, e:= end, t:= target
        def binary_search(s: int, e: int, t: int) -> bool:
            if s > e:
                return False
            
            mid = s + ((e - s) >> 1)
            if mid * mid == t:
                return True
            
            if mid * mid > t:
                return binary_search(s, mid - 1, t)
            return binary_search(mid + 1, e, t)
        
        for a in range(c + 1):
            if a * a > c:
                break
            b = c - a * a
            if binary_search(0, b, b):
                return True
            
        return False