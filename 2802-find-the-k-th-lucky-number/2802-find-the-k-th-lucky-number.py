class Solution:
    def kthLuckyNumber(self, k: int) -> str:
        # Increment k to account for 1-based indexing
        k = k + 1
        
        # Convert k to a binary string (up to the most significant '1')
        kth_lucky_num = bin(k)[3:]
        
        # Replace '0' with '4' aand '1' with '7' in the binary string
        kth_lucky_num = kth_lucky_num.replace('0', '4').replace('1', '7')
        
        return kth_lucky_num
        