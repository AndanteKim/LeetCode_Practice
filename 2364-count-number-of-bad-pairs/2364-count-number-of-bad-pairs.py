class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        n, diff_count = len(nums), dict()

        for pos, num in enumerate(nums):
            diff_count[num - pos] = diff_count.get(num - pos, 0) + 1
        
        ans = n * (n - 1) >> 1
        for _, curr_count in diff_count.items():
            curr_good_pairs = ((curr_count - 1) * curr_count) >> 1
            ans -= curr_good_pairs

        return ans