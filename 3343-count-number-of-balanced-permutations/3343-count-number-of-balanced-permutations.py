class Solution:
    def countBalancedPermutations(self, num: str) -> int:
        mod, num = 1_000_000_007, list(map(int, num))
        tot = sum(num)

        # Base case
        if tot % 2 != 0:
            return 0

        target, n = tot >> 1, len(num)
        cnt = Counter(num)
        max_odd = (n + 1) >> 1
        psum = [0] * 11

        for i in range(9, -1, -1):
            psum[i] = psum[i + 1] + cnt[i]
        
        @cache
        def dfs(pos: int, curr: int, odd_cnt: int) -> int:
            # If the remaining positions cannot complete a legal placement, or the sum of the elements\
            # in the current odd positions is greater than the target value
            if odd_cnt < 0 or psum[pos] < odd_cnt or curr > target:
                return 0
            
            if pos > 9:
                return int(curr == target and odd_cnt == 0)
            
            # Even-numbered positions remaining to be filled
            even_cnt = (psum[pos] - odd_cnt)
            ans = 0

            for i in range(max(0, cnt[pos] - even_cnt), min(cnt[pos], odd_cnt) + 1):
                # Place i of the current number at odd positions, and cnt[pos] - i\
                # at even positions
                ways = comb(odd_cnt, i) * comb(even_cnt, cnt[pos] - i) % mod
                ans += ways * dfs(pos + 1, curr + i * pos, odd_cnt - i)
            return ans % mod
        
        return dfs(0, 0, max_odd)