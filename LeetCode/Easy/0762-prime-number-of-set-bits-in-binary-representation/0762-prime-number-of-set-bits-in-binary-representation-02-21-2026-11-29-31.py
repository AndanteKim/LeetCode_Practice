class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:
        ans = 0
        
        for num in range(left, right + 1):
            cnt, is_prime = bin(num).count('1'), True

            if cnt <= 1:
                continue
            
            for p in range(2, int(cnt ** 0.5) + 1):
                if cnt % p == 0:
                    is_prime = False
                    break

            if is_prime:
                ans += 1

        return ans