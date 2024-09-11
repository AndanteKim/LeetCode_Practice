import functools

class Solution:
    def reverseBits(self, n: int) -> int:
        ans, power = 0, 24
        while n:
            ans += self.reverseByte(n & 0xFF) << power
            n = n >> 8
            power -= 8
            
        return ans
    
    # memoization with decorator
    @functools.lru_cache(maxsize = 256)
    def reverseByte(self, byte: int) -> int:
        return (byte * 0x0202020202 & 0x010884422010) % 1023