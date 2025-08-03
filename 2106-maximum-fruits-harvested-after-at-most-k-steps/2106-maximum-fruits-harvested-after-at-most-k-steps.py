class Solution:
    def maxTotalFruits(self, fruits: List[List[int]], startPos: int, k: int) -> int:
        n = len(fruits)
        sum_ = [0] * (n + 1)
        indices = [0] * n

        for i in range(n):
            sum_[i + 1] = sum_[i] + fruits[i][1]
            indices[i] = fruits[i][0]
        
        ans = 0
        for x in range((k >> 1) + 1):
            # Move left x steps, then right (k - 2x) steps
            y = k - 2 * x
            left, right = startPos - x, startPos + y
            start = bisect_left(indices, left)
            end = bisect_right(indices, right)
            ans = max(ans, sum_[end] - sum_[start])
        
            # Move right x steps, then left (k - 2x) steps
            y = k - 2 * x
            left, right = startPos - y, startPos + x
            start, end = bisect_left(indices, left), bisect_right(indices, right)
            ans = max(ans, sum_[end] - sum_[start])

        return ans