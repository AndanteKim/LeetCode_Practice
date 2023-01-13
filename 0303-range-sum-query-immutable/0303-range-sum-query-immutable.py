class NumArray:

    def __init__(self, nums: List[int]):
        self.nums, total, self.prefix_sum = nums, 0, (0, )
        
        for i in range(len(self.nums)):
            self.prefix_sum += (total + self.nums[i], )
            total += self.nums[i]
        print(self.prefix_sum)
        
    def sumRange(self, left: int, right: int) -> int:
        return self.prefix_sum[right+1] - self.prefix_sum[left]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)