class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + nums[i]

        ans = 0
        for j in range(n):
            lo, hi, i = 0, j, j
            while lo <= hi:
                mid = lo + ((hi - lo) >> 1)
                length = j - mid + 1
                total = prefix[j + 1] - prefix[mid]
                score = total * length
                if score < k:
                    i = mid
                    hi = mid - 1
                else:
                    lo = mid + 1
            
            # If length 1 and score is greater than equal to k, skip it
            if i == j and nums[j] >= k:
                continue
            # else this will be valid because of binary search
            ans += j - i + 1

        return ans