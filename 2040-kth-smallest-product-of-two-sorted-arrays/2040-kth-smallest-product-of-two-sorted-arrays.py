class Solution:
    def kthSmallestProduct(self, nums1: List[int], nums2: List[int], k: int) -> int:
        def f(x1: int, v: int) -> int:
            if x1 > 0:
                return bisect_right(nums2, v // x1)
            elif x1 < 0:
                return n - bisect_left(nums2, -(-v // x1))
            else:
                return n if v >= 0 else 0


        m, n = len(nums1), len(nums2)
        candidates = [nums1[0] * nums2[0], nums1[-1] * nums2[0], nums1[0] * nums2[-1], nums1[-1] * nums2[-1]]
        left, right = min(candidates), max(candidates)

        while left <= right:
            mid = left + ((right - left) >> 1)
            count = 0
            for i in range(m):
                count += f(nums1[i], mid)
            if count < k:
                left = mid + 1
            else:
                right = mid - 1
        
        return left