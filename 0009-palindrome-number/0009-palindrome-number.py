class Solution:
    def isPalindrome(self, x: int) -> bool:
        # Special cases:
        # 1 ) When x < 0, x isn't a palindrome.
        # 2 ) If the last digit of the number is 0, in order to be a palindrome,
        # the first digit of the number also needs to be 0.
        # Only 0 satisfy this property.
        if x < 0 or (x % 10 == 0 and x != 0):
            return False
        
        reverted_num = 0
        
        while x > reverted_num:
            reverted_num = reverted_num * 10 + x % 10
            x //= 10
            
        # When the length an odd number, we can get rid of the middle digit by reverted_num // 10
        # For example, when the input is 12321, at the end of the while loop we get x = 12, reverted_num = 123,
        # since the middle digit doesn't matter in palindrome(it'll always equal to itself), we can simply get rid of it.
        return x == reverted_num or x == reverted_num // 10