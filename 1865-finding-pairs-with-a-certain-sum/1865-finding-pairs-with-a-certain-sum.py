class FindSumPairs:

    def __init__(self, nums1: List[int], nums2: List[int]):
        self.nums1, self.nums2 = nums1, nums2
        self.freq2 = Counter(nums2)
        self.n1 = len(nums1)

    def add(self, index: int, val: int) -> None:
        self.freq2[self.nums2[index]] -= 1
        self.nums2[index] += val
        self.freq2[self.nums2[index]] += 1

    def count(self, tot: int) -> int:
        pairs = 0
        for i in range(self.n1):
            target = tot - self.nums1[i]
            pairs += self.freq2[target]

        return pairs


# Your FindSumPairs object will be instantiated and called as such:
# obj = FindSumPairs(nums1, nums2)
# obj.add(index,val)
# param_2 = obj.count(tot)