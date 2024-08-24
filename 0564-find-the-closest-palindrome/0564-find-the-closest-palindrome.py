class Solution:
    def nearestPalindromic(self, n: str) -> str:
        len_n = len(n)
        i = (len_n >> 1) - 1 if len_n % 2 == 0 else (len_n >> 1)
        
        first_half = int(n[: i + 1])
        """
        Generate possible palindromic candidates:
        1. Create a palindrome by mirroring the first half.
        2. Create a palindrome by mirroring the first half incremented by 1.
        3. Create a palindrome by mirroring the first half decremented by 1.
        4. Handle edge cases by considering palindromes of the form 999...
           and 100...001 (smallest and largest n-digit palindromes).
        """
        possibilities = []
        possibilities.append(self.half_to_palindrome(first_half, len_n % 2 == 0))
        possibilities.append(self.half_to_palindrome(first_half + 1, len_n % 2 == 0))
        possibilities.append(self.half_to_palindrome(first_half - 1, len_n % 2 == 0))
        possibilities.append(10 ** (len_n - 1) - 1)
        possibilities.append(10 ** len_n + 1)
        
        diff = float("inf")
        ans = 0
        num = int(n)
        
        for cand in possibilities:
            if cand == num:
                continue
            if abs(cand - num) < diff:
                diff = abs(cand - num)
                ans = cand
            elif abs(cand - num) == diff:
                ans = min(ans, cand)
        
        return str(ans)
    
    def half_to_palindrome(self, left: int, even: bool) -> int:
        ans = left
        if not even:
            left //= 10
        
        while left > 0:
            ans = ans * 10 + left % 10
            left //= 10
            
        return ans
        