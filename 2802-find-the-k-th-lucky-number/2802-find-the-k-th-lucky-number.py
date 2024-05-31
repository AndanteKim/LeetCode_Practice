class Solution:
    def kthLuckyNumber(self, k: int) -> str:
        c = 0 # The number of digits in the kth lucky number
        num_count = 0 # The number of lucky numbers with c or fewer digits
        while num_count < k:
            c += 1
            num_count += 2 ** c
            
        # Calculate the number of lucky numbers with c digits before the kth lucky number
        x = k - 1 - (num_count - (2 ** c))
        
        # Build result using x by pretending 4 for 0 and 1 for 7
        kth_lucky_num = ""
        for i in range(c):
            if x % 2 == 1:
                digit = "7"
            else:
                digit = "4"
                
            kth_lucky_num = "".join((digit, kth_lucky_num))
            x >>= 1
            
        return kth_lucky_num