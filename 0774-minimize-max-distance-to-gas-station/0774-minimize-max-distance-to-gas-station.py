class Solution:
    def minmaxGasDist(self, stations: List[int], k: int) -> float:
        def possible(d: float) -> bool:
            total = 0.0

            for i in range(n - 1):
                total += int((stations[i + 1] - stations[i]) / d)
            
            return total <= k


        n = len(stations)
        lo, hi = 0, 10 ** 8

        while hi - lo > 1e-6:
            mid = (lo + hi) / 2.0
            if possible(mid):
                hi = mid
            else:
                lo = mid
        
        return lo