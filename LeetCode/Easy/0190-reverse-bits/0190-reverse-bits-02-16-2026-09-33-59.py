class Solution:
    def reverseBits(self, n: int) -> int:
        original, i = [], 0
        while n > 0:
            original.append(chr(n % 2 + 48))
            n >>= 1
            i += 1

        for i in range(32 - i):
            original.append('0')
        
        ans = 0
        for j in range(32):
            ans += (ord(original[j]) - 48) * (2 ** (31 - j))
        
        return ans