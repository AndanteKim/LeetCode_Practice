class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        # base case
        if a | b == c:
            return 0
        
        ans, flip, max_val = 0, 1, max(a, b, c)
        
        while flip <= max_val:
            a_bit, b_bit, c_bit = a & 1, b & 1, c & 1
            if a_bit == 1 and b_bit == 1 and c_bit == 1:
                flip <<= 1
                a >>= 1
                b >>= 1
                c >>= 1
                continue
            ans += abs(c_bit - a_bit - b_bit)
            flip <<= 1
            a >>= 1
            b >>= 1
            c >>= 1
        
        return ans