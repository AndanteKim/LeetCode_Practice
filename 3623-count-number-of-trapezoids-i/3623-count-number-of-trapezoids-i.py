class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        pt_nums, mod = defaultdict(int), 10 ** 9 + 7
        ans, total_sum = 0, 0

        for x, y in points:
            pt_nums[y] += 1
        
        for p_num in pt_nums.values():
            edge = p_num * (p_num - 1) >> 1
            ans = (ans + edge * total_sum) % mod
            total_sum = (total_sum + edge) % mod

        return ans