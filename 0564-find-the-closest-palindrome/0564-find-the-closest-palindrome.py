class Solution:
    def convert(self, num: int) -> int:
        s = str(num)
        n = len(s)
        l, r = (n - 1) >> 1, n >> 1
        
        s_list = list(s)
        while l >= 0:
            s_list[r] = s_list[l]
            r += 1
            l -= 1
            
        return int("".join(s_list))
    
    def next_palindrome(self, num: int) -> int:
        left, right = 0, num
        ans = float("-inf")
        
        while left <= right:
            mid = left + ((right - left) >> 1)
            palin = self.convert(mid)
            
            if palin < num:
                ans = palin
                left = mid + 1
            else:
                right = mid - 1
                
        return ans
    
    def prev_palindrome(self, num: int) -> int:
        left, right = num, int(1e18)
        ans = float("-inf")
        
        while left <= right:
            mid = left + ((right - left) >> 1)
            palin = self.convert(mid)
            if palin > num:
                ans = palin
                right = mid - 1
            else:
                left = mid + 1
                
        return ans
    
    def nearestPalindromic(self, n: str) -> str:
        num = int(n)
        a = self.next_palindrome(num)
        b = self.prev_palindrome(num)
        
        if abs(a - num) <= abs(b - num):
            return str(a)
        return str(b)