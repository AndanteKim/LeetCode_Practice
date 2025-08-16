class Solution:
    def maximum69Number (self, num: int) -> int:
        # Since we start with the lowest digit, initialize curr_digit = 0.
        curr_digit, idx_1st_6, num_cp = 0, -1, num

        # Check every digit of 'num_copy' from low to high.
        while num_cp:
            # If the current digit is '6', record it as the highest digit of 6.
            if num_cp % 10 == 6:
                idx_1st_6 = curr_digit
            
            # Move on to the next digit.
            num_cp //= 10
            curr_digit += 1

        # If we don't find any digit of '6', return the original number,
        # otherwise, increment 'num' by the difference made by the first '6'.
        return num if idx_1st_6 == -1 else num + 3 * 10 ** idx_1st_6