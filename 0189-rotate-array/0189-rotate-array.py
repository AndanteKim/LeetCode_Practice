class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        queue = deque(nums)
        
        for _ in range(k):
            elem = queue.pop()
            queue.appendleft(elem)
        
        for i in range(len(nums)):
            nums[i] = queue.popleft()