class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        n, sum_arr = len(nums), nums[:]

        if len(sum_arr) == 1:
            return sum_arr[0]

        while len(sum_arr) > 1:
            curr = []
            for i in range(len(sum_arr) - 1):
                curr.append((sum_arr[i] + sum_arr[i + 1]) % 10)

            sum_arr = curr        

        return sum_arr[0]