class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        
        elems = []
        while x > 0:
            elems.append(x % 10)
            x //= 10
            
        return elems == elems[::-1]