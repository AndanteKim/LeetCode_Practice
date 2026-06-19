class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        ans, curr_sum = 0, 0

        for a in gain:
            curr_sum += a
            ans = max(ans, curr_sum)
        return ans