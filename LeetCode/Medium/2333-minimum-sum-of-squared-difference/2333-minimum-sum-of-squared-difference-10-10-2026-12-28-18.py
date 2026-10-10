class Solution:
    def minSumSquareDiff(self, nums1: list[int], nums2: list[int], k1: int, k2: int) -> int:
        n, k = len(nums1), k1 + k2
        ans, diffs = 0, [abs(a - b) for a, b in zip(nums1, nums2)]

        if sum(diffs) <= k:
            return 0

        diffs.sort(reverse = True)
        diffs.append(0)

        for i in range(1, n + 1):
            cost = (diffs[i - 1] - diffs[i]) * i

            if cost > k:
                q, r = divmod(k, i)
                hi = diffs[i - 1] - q
                return (
                    (hi ** 2) * (i - r)
                    + ((hi - 1) ** 2) * r
                    + sum(x ** 2 for x in diffs[i:n])
                )

            k -= cost 

        return 0