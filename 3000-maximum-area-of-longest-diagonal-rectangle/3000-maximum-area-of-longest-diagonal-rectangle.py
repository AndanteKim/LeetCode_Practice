class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        ans, max_d = 0, 0

        for l, w in dimensions:
            d = (l ** 2 + w ** 2) ** 0.5

            if d >= max_d:
                if d == max_d:
                    ans = max(ans, l * w)
                else:
                    ans, max_d = l * w, d

        return ans