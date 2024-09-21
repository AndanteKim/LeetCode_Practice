class Solution:
    def preprocess(self, s: str) -> str:
        return "^" + "#" + "#".join(s) + "#$"
    
    def shortestPalindrome(self, s: str) -> str:
        # Manacher algorithm
        # Return early if the string is null or empty
        if not s:
            return s
        
        # Preprocess the string to handle palindromes uniformly
        modified_s = self.preprocess(s)
        n = len(modified_s)
        palindrome_rad_arr = [0] * n
        center, right_bound = 0, 0
        max_palindrome_len = 0
        
        # Iterate through each character in the modified string
        for i in range(1, n - 1):
            mirror_idx = 2 * center - i
        
            if right_bound > i:
                palindrome_rad_arr[i] = min(right_bound - i, palindrome_rad_arr[mirror_idx])
            
            # Expand around the current center while characters match
            while modified_s[i + 1 + palindrome_rad_arr[i]] == modified_s[i - 1 - palindrome_rad_arr[i]]:
                palindrome_rad_arr[i] += 1
                
            # Update the center and right boundary if the palindrome extend beyond the current boundary
            if i + palindrome_rad_arr[i] > right_bound:
                center = i
                right_bound = i + palindrome_rad_arr[i]
                
            # Update the maximum length of palindrome starting at the beginning
            if i - palindrome_rad_arr[i] == 1:
                max_palindrome_len = max(max_palindrome_len, palindrome_rad_arr[i])
                
        # Construct the shortest palindrome by reversing the suffix and prepending it to the orignal string
        suffix = s[max_palindrome_len:][::-1]
        return suffix + s