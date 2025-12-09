class Solution:
    def specialTriplets(self, nums: List[int]) -> int:
        mod, ans = 10 ** 9 + 7, 0
        nums_cnt, nums_partial_cnt = dict(), dict()

        for num in nums:
            nums_cnt[num] = nums_cnt.get(num, 0) + 1

        ans = 0
        for num in nums:
            target = num * 2
            l_cnt = nums_partial_cnt.get(target, 0)
            nums_partial_cnt[num] = nums_partial_cnt.get(num, 0) + 1
            r_cnt = nums_cnt.get(target, 0) - nums_partial_cnt.get(target, 0)
            ans = (ans + l_cnt * r_cnt) % mod
        
        return ans