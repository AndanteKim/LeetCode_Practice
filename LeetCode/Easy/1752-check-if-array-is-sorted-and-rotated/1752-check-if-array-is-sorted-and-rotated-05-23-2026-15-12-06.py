class Solution:
    def check(self, nums: List[int]) -> bool:
        n = len(nums)
        if n <= 1:
            return True

        inv_cnt = 0

        for i in range(1, n):
            if nums[i - 1] > nums[i]:
                inv_cnt += 1
                if inv_cnt > 1:
                    return False

        if nums[0] < nums[-1]:
            inv_cnt += 1
        
        return inv_cnt <= 1