class Solution:
    def largestSquareArea(self, bottomLeft: List[List[int]], topRight: List[List[int]]) -> int:
        ans, m = 0, len(bottomLeft)

        for i in range(m - 1):
            b1_x, b1_y = bottomLeft[i]
            for j in range(i + 1, m):
                b2_x, b2_y = bottomLeft[j]

                b_max_x, b_max_y = max(b1_x, b2_x), max(b1_y, b2_y)

                t1_x, t1_y = topRight[i]
                t2_x, t2_y = topRight[j]
                t_min_x, t_min_y = min(t1_x, t2_x), min(t1_y, t2_y)

                length = max(0, min((t_min_x - b_max_x), (t_min_y - b_max_y)))
                ans = max(ans, length ** 2)

        return ans