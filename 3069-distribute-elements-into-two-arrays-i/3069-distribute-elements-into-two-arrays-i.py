class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        arr = [0] * n
        arr[0], arr[-1] = nums[0], nums[1]
        idx, rev_idx = 0, n - 1

        for i in range(2, n):
            if arr[idx] > arr[rev_idx]:
                idx += 1
                arr[idx] = nums[i]
            else:
                rev_idx -= 1
                arr[rev_idx] = nums[i]

        l, r = rev_idx, n - 1
        while l < r:
            arr[l], arr[r] = arr[r], arr[l]
            l += 1
            r -= 1
        return arr