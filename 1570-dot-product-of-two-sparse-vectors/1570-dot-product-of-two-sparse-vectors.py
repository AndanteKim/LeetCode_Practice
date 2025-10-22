class SparseVector:
    def __init__(self, nums: List[int]):
        self.nums, self.m = nums, len(nums)

    # Return the dotProduct of two sparse vectors
    def dotProduct(self, vec: 'SparseVector') -> int:
        nums2, self.n = vec.nums, len(vec.nums)
        return -1 if self.m != self.n else sum(e1 * e2 for e1, e2 in zip(self.nums, nums2))

# Your SparseVector object will be instantiated and called as such:
# v1 = SparseVector(nums1)
# v2 = SparseVector(nums2)
# ans = v1.dotProduct(v2)