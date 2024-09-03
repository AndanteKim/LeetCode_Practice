class Solution:
    def getLucky(self, s: str, k: int) -> int:
        curr_num = 0
        
        # Convert the string to a number by summing digit values
        for c in s:
            pos = ord(c) - 96
            while pos > 0:
                curr_num += pos % 10
                pos //= 10
                
        # Apply digit sum transformations k - 1 times
        for i in range(1, k):
            digit_sum = 0
            while curr_num > 0:
                digit_sum += curr_num % 10
                curr_num //= 10
                
            curr_num = digit_sum
                
        return curr_num