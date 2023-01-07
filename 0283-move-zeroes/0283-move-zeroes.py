class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        queue = deque(nums)
        i = 0
        while queue:
            q = queue.popleft()
            if q != 0:
                nums[i] = q
                i += 1
        for i in range(i, len(nums)):
            nums[i] = 0