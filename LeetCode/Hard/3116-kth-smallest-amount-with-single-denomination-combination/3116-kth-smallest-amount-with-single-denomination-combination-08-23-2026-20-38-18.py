class Solution:
    def findKthSmallest(self, coins: List[int], k: int) -> int:
        def count(x: int) -> int:
            cnt = 0

            for mask in range(1, m):
                if lcm[mask] <= x:
                    if bit_cnt[mask] & 1:
                        cnt += x // lcm[mask]
                    else:
                        cnt -= x // lcm[mask]
            
            return cnt

        coins.sort()
        n = len(coins)
        m = 1 << n
        left, right = k, coins[0] * k + 1

        bit_cnt, lcm = [0] * m, [0] * m

        for mask in range(1, m):
            curr_lcm = 1

            for i, coin in enumerate(coins):
                if (mask >> i) & 1:
                    curr_lcm = curr_lcm // gcd(curr_lcm, coin) * coin
                    bit_cnt[mask] += 1
            lcm[mask] = curr_lcm
        
        while left < right:
            mid = (left + right) >> 1

            if count(mid) >= k:
                right = mid
            else:
                left = mid + 1
        
        return left