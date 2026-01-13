class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        def check(lim_y: float) -> bool:
            area = 0

            for x, y, l in squares:
                if y < lim_y:
                    area += l * min(lim_y - y, l)
            
            return area >= total_area / 2
        
        max_y, total_area = 0, 0

        for x, y, l in squares:
            total_area += l ** 2
            max_y = max(max_y, y + l)

        lo, hi = 0, max_y
        eps = 1e-5

        while abs(hi - lo) > eps:
            mid = (lo + hi) / 2
            if check(mid):
                hi = mid
            else:
                lo = mid

        return hi