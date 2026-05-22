class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def bs(lo: int, hi: int) -> int:
            while lo <= hi:
                mid = (lo + hi) >> 1
                if nums[mid] == target:
                    return mid
                elif nums[mid] > target:
                    hi = mid - 1
                else:
                    lo = mid + 1

            return -1
        

        n = len(nums)
        left, right = 0, n - 1

        while left <= right:
            mid = (left + right) >> 1
            if nums[mid] > nums[-1]:
                left = mid + 1
            else:
                right = mid - 1

        ans = bs(0, left - 1)

        if ans != -1:
            return ans

        return bs(left, n - 1)