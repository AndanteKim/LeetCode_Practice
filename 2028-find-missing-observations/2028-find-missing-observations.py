class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        m = len(rolls)
        needed = mean * (m + n)
        for roll in rolls:
            needed -= roll
            
        # Base case
        if n > needed or 6 * n < needed:
            return []
        
        # Find n's average
        n_avg = needed // n
        n_arr, remain, i = [n_avg] * n, needed - (n_avg * n), n - 1
        
        while remain > 0:
            if 1 <= n_arr[i % n] < 6:
                n_arr[i % n] += 1
                remain -= 1
            i += 1
        
        return n_arr