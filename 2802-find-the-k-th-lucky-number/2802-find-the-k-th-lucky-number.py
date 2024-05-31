class Solution:
    def kthLuckyNumber(self, k: int) -> str:
        # Increment k to account for 1-based indexing
        k += 1;
        
        # For each digit in the binary representation of k except the most significant
        # Pretend 4 to the result if the digit is 0 and 7 otherwise
        kth_lucky_num = ""
        
        while k > 1:
            kth_lucky_num = "".join((("7" if k & 1 else "4"), kth_lucky_num))
            k >>= 1
            
        return kth_lucky_num
        